#!/bin/bash
# This script launches three MAVROS instances, one for each simulated drone.
# Each instance is placed in its own namespace (drone1, drone2, drone3) and
# connects to the unique UDP ports exposed by the PX4 SITL multi-vehicle script.

# --- THIS IS THE CRITICAL FIX ---
# We are adding the 'fcu_protocol:=v2.0' argument to each command.
# This explicitly tells MAVROS to use the MAVLink v2.0 protocol, which
# helps to avoid the handshake timeout and ensures all services start correctly.

echo "Starting MAVROS bridge for Drone 1..."
ros2 launch mavros px4.launch fcu_url:="udp://:14540@127.0.0.1:14580" fcu_protocol:=v2.0 namespace:=drone1 &

echo "Starting MAVROS bridge for Drone 2..."
ros2 launch mavros px4.launch fcu_url:="udp://:14541@127.0.0.1:14581" fcu_protocol:=v2.0 namespace:=drone2 &

echo "Starting MAVROS bridge for Drone 3..."
ros2 launch mavros px4.launch fcu_url:="udp://:14542@127.0.0.1:14582" fcu_protocol:=v2.0 namespace:=drone3 &

echo "All MAVROS bridges launched."
