#!/usr/bin/env python3

import time
import socket
import threading
import serial.tools.list_ports
from pymavlink import mavutil

"""
This script continuously scans for any USB telemetry radios plugged into the computer.
For each radio it finds, it starts a dedicated thread to listen for MAVLink data.
When it receives data from any drone, it forwards it to a single UDP port (14550) that your mavros node will listen to.
It also listens for commands coming back from mavros and intelligently routes them to the correct drone via the correct radio.
"""

# --- Configuration ---
# The UDP port MAVROS will listen on. The aggregator sends data TO this port.
MAVROS_UDP_PORT = 14550
# The UDP port the aggregator will listen on for messages FROM MAVROS.
AGGREGATOR_LISTEN_PORT = 14551

# --- HARDWARE DEPENDENCY 3: BAUD RATE ---
# This baud rate MUST match the configuration of your physical telemetry radios.
# Common values are 57600 (default for many) or 115200.
# If this is wrong, the script will fail to communicate.
SERIAL_BAUD_RATE = 57600

# How often to scan for new serial ports (in seconds).
PORT_SCAN_INTERVAL = 5

class DroneConnection:
    """
    Manages a connection to a single drone via a serial port.
    It reads data from the drone and forwards it to a UDP port,
    and receives data from a queue to write back to the drone.
    """
    def __init__(self, port, baud, mavros_host='127.0.0.1', mavros_port=MAVROS_UDP_PORT):
        self.port = port
        self.baud = baud
        self.mavros_addr = (mavros_host, mavros_port)
        self.mav_connection = None
        self.udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.running = False
        self.system_id = -1 # Unidentified until first message
        
        self.read_thread = threading.Thread(target=self._read_from_drone)
        
    def start(self):
        """Starts the connection and the reading thread."""
        try:
            # --- HARDWARE DEPENDENCY 1: SERIAL COMMUNICATION ---
            # This line uses the 'pyserial' library to open a direct connection
            # to the USB telemetry radio. It assumes the hardware provides a
            # standard serial interface.
            self.mav_connection = mavutil.mavlink_connection(self.port, baud=self.baud)
            self.running = True
            self.read_thread.start()
            print(f"INFO: Started connection on {self.port}")
            return True
        except Exception as e:
            print(f"ERROR: Could not start connection on {self.port}. Reason: {e}")
            return False

    def stop(self):
        """Stops the connection and cleans up resources."""
        self.running = False
        if self.read_thread.is_alive():
            self.read_thread.join()
        if self.mav_connection:
            self.mav_connection.close()
        self.udp_socket.close()
        print(f"INFO: Stopped connection on {self.port}")

    def _read_from_drone(self):
        """Continuously reads messages from the drone and forwards them via UDP."""
        while self.running:
            try:
                # Wait for a new MAVLink message from the serial port
                msg = self.mav_connection.recv_match(blocking=True, timeout=1)
                if msg is None:
                    continue

                # If this is the first message, store the drone's system ID
                if self.system_id == -1:
                    self.system_id = msg.get_srcSystem()
                    print(f"INFO: Detected Drone with System ID {self.system_id} on {self.port}")
                    # Register this drone in the global routing table
                    with routing_lock:
                        system_routing_table[self.system_id] = self

                # Forward the raw message buffer over UDP to MAVROS
                self.udp_socket.sendto(msg.get_msgbuf(), self.mavros_addr)

            except Exception as e:
                print(f"ERROR: Lost connection on {self.port}. Reason: {e}")
                self.running = False

    def write_to_drone(self, data):
        """Writes data received from UDP back to the drone's serial port."""
        if self.mav_connection:
            try:
                self.mav_connection.write(data)
            except Exception as e:
                print(f"ERROR: Could not write to {self.port}. Reason: {e}")


# --- Global Variables for Routing and Thread Management ---
# A thread-safe dictionary to map a drone's System ID to its DroneConnection object
# e.g., {1: DroneConnection_Object_for_Drone_1}
system_routing_table = {}
routing_lock = threading.Lock()

# A dictionary to keep track of active connections by their port name
# e.g., {'/dev/ttyUSB0': DroneConnection_Object_1}
active_connections = {}

def udp_listener():
    """
    Listens for MAVLink messages coming from MAVROS (or other GCS) on a UDP port
    and routes them to the correct drone via its serial connection.
    """
    # Note: Using mavutil.mavlink_connection for listening simplifies parsing
    # and correctly identifying the target system ID from GCS messages.
    # The 'udpin' string format is specific to pymavlink.
    udp_mav_connection = mavutil.mavlink_connection(f'udpin:0.0.0.0:{AGGREGATOR_LISTEN_PORT}')
    print(f"INFO: UDP Listener started on port {AGGREGATOR_LISTEN_PORT}")

    while True:
        try:
            # Wait for a message from MAVROS
            msg = udp_mav_connection.recv_match(blocking=True)
            if msg is None:
                continue

            # Pymavlink's mavlink_connection object automatically handles parsing.
            # We need to find the target system ID to route the message.
            # For most messages, this is in the header.
            target_system_id = msg.get_header().target_system
            
            # Route the message to the correct drone
            with routing_lock:
                target_drone = system_routing_table.get(target_system_id)
            
            if target_drone:
                # We forward the original, raw byte buffer of the message
                target_drone.write_to_drone(msg.get_msgbuf())
            else:
                # This can happen if MAVROS sends a command before the drone's first message has been received
                # Or if it's a broadcast message (target_system=0), which we can choose to send to all drones.
                if target_system_id == 0: # Broadcast
                    with routing_lock:
                        for drone in system_routing_table.values():
                            drone.write_to_drone(msg.get_msgbuf())
                # else:
                #     print(f"WARN: Received message for unknown System ID {target_system_id}. Discarding.")
                pass

        except Exception as e:
            print(f"ERROR: Error in UDP listener: {e}")


def main():
    """
    The main function that scans for serial ports and manages drone connections.
    """
    print("--- MAVLink Aggregator Starting ---")

    # Start the UDP listener in a separate thread
    listener_thread = threading.Thread(target=udp_listener, daemon=True)
    listener_thread.start()

    try:
        while True:
            # --- HARDWARE DEPENDENCY 2: SERIAL PORT NAME ---
            # This line scans for serial ports. The 'if 'USB' in p.device' part
            # assumes your radios will appear as '/dev/ttyUSB0', '/dev/ttyUSB1', etc.
            # If your hardware appears as something else (e.g., '/dev/ttyACM0'),
            # you will need to change this filter.
            available_ports = [p.device for p in serial.tools.list_ports.comports() if 'USB' in p.device]
            
            # --- Handle new connections ---
            for port in available_ports:
                if port not in active_connections:
                    print(f"INFO: New port detected: {port}")
                    conn = DroneConnection(port, SERIAL_BAUD_RATE)
                    if conn.start():
                        active_connections[port] = conn

            # --- Handle disconnected devices ---
            disconnected_ports = []
            for port, conn in list(active_connections.items()):
                if not conn.running:
                    print(f"INFO: Connection on {port} is no longer running. Cleaning up.")
                    conn.stop()
                    disconnected_ports.append(port)
                    # Remove from routing table
                    with routing_lock:
                        if conn.system_id in system_routing_table and system_routing_table[conn.system_id] == conn:
                            del system_routing_table[conn.system_id]
            
            # Clean up the active connections dictionary
            for port in disconnected_ports:
                if port in active_connections:
                    del active_connections[port]

            time.sleep(PORT_SCAN_INTERVAL)

    except KeyboardInterrupt:
        print("\n--- Shutting Down Aggregator ---")
        for conn in active_connections.values():
            conn.stop()
        print("All connections closed. Exiting.")


if __name__ == "__main__":
    main()
