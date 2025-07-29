# Aether GCS: A High-Level Overview

The Aether project is a sophisticated system for commanding and controlling a fleet of autonomous drones. Instead of a simple remote control for one drone, it's a complete command center for a team of robotic vehicles. The entire system is built on a professional, distributed architecture, which can be broken down into three core components: The Drones, The Ground Control Station, and The Network.

## 1. The Drones: The Autonomous Agents
Each drone in the fleet is an independent, intelligent robot. It has two "brains" working together:

### The Pilot (The Flight Controller): This is the Pixhawk hardware running the PX4 firmware. Its only job is to handle the physics of flight—keeping the drone stable, managing the motors, and executing low-level commands like "fly to this coordinate." It's the expert pilot focused on the immediate task of flying.

### The Mission Specialist (The Companion Computer): This is the Raspberry Pi. It's the high-level brain that understands the overall mission. It runs the ROS 2 software that handles:

#### Communication: Talking to the GCS and other drones over the network.

#### Safety: Running the real-time collision avoidance logic to keep itself safe from its neighbors.

#### Mission Tasks: Interfacing with the specialized fish-finding sensor and running the detection algorithms.

## 2. The Ground Control Station (GCS): The Command Center
The GCS is the single interface where the human operator manages the entire fleet. It is not a remote control; it is a strategic command and monitoring tool.

### Fleet Monitoring: The GCS displays a "God's-eye view" of the entire operation on a single screen. The operator can see the location, battery level, and status of every drone in real-time.

### Mission Planning: The operator uses the GCS to create and assign high-level tasks to the drones, such as defining a search area for the fleet to investigate.

### Human Oversight: The GCS is the ultimate safety tool. It allows the operator to monitor the fleet's autonomous behavior and intervene at any time by issuing high-level commands like "Pause Mission" or "Return to Launch."

## 3. The Network: The Communication Link
The network is the invisible fabric that connects everything.

### The Connection: For the demo, all drones and the GCS connect to a single Wi-Fi router on the ground. In the final version, each drone will have its own Starlink terminal, giving the fleet virtually unlimited range.

### The Secure Layer (Tailscale): We use a software tool called Tailscale to create a secure, private network that works over any internet connection. This makes all the drones and the GCS feel like they are on the same local network, even if they are miles apart.

### The Language (ROS 2): All the high-level communication—fleet status, mission plans, and collaborative data—is sent using the powerful ROS 2 robotics framework.

## The Workflow in Action
A typical mission looks like this:

1. The operator uses the GCS to draw a search pattern on a map.

2. The GCS sends this mission plan over The Network to a specific drone.

3. The Drone's Mission Specialist (Raspberry Pi) receives the plan and tells its Pilot (the Flight Controller) to begin.

4. As the drone flies, it constantly sends its status back to the GCS and shares its position with other drones for collision avoidance.

5. If it detects fish, its Mission Specialist sends an alert back to the GCS, which then displays it for the operator.
