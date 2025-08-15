#!/usr/bin/env python3

import asyncio
from mavsdk import System

async def run():
    """
    This script connects to three simulated drones, commands them to take off
    and hover for 15 seconds, and then commands them to land.
    """
    # The default GCS broadcast ports for the first three PX4 instances
    drone_addresses = [
        "udp://:14550",
        "udp://:14551",
        "udp://:14552"
    ]
    
    drones = [System(mavsdk_server_address='localhost', port=50051 + i) for i in range(len(drone_addresses))]

    # Connect to all drones concurrently
    connect_tasks = []
    for i, addr in enumerate(drone_addresses):
        print(f"Connecting to Drone {i+1} at {addr}...")
        connect_tasks.append(asyncio.create_task(drones[i].connect(system_address=addr)))
    
    await asyncio.gather(*connect_tasks)
    print("--- All drones connected.")

    print("Waiting for drones to have a global position estimate...")
    
    # Wait for all drones to be healthy and ready
    health_tasks = []
    for i, drone in enumerate(drones):
        async def check_health(d, drone_num):
            async for health in d.telemetry.health():
                if health.is_global_position_ok and health.is_home_position_ok:
                    print(f"--- Drone {drone_num} is ready.")
                    break
        health_tasks.append(asyncio.create_task(check_health(drone, i + 1)))
    await asyncio.gather(*health_tasks)
    print("--- All drones are ready.")

    print("-- Arming all drones")
    arm_tasks = [asyncio.create_task(drone.action.arm()) for drone in drones]
    await asyncio.gather(*arm_tasks)

    print("-- Taking off all drones")
    takeoff_tasks = [asyncio.create_task(drone.action.takeoff()) for drone in drones]
    await asyncio.gather(*takeoff_tasks)

    print("-- Waiting for 15 seconds...")
    await asyncio.sleep(15)

    print("-- Landing all drones")
    land_tasks = [asyncio.create_task(drone.action.land()) for drone in drones]
    await asyncio.gather(*land_tasks)


if __name__ == "__main__":
    # Run the asyncio event loop
    asyncio.run(run())
