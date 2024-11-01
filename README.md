# Passenger Recovery Simulation

This project implements a **queuing system simulation** in **C++** to model passenger handling at airport security. By applying **queuing theory**, it evaluates different scenarios and optimizes passenger processing based on **arrival rate, service rate, and buffer size**. The simulation offers insights into system performance for **single-server** and **multi-server** models, both with **finite** and **infinite buffers**.

### Project Overview

This project uses **M/M/1** and **M/M/m** queuing models:
- **M/M/1**: A single-server system, where passengers arrive at random intervals and are processed one at a time.
- **M/M/m**: A multi-server system, where multiple servers (scanners) are available to process passengers simultaneously.

Each model has variations:
- **Infinite Buffer**: No limit on the number of passengers in the queue.
- **Finite Buffer**: The queue has a fixed capacity; once full, new passengers are turned away.

### Key Metrics

The simulation calculates essential performance metrics:
- **Average Waiting Time**: The average time passengers spend waiting in the queue.
- **Average Queue Length**: The average number of passengers in the queue.
- **System Utilization**: The proportion of time the server(s) are busy.

These metrics provide valuable insights for optimizing airport security handling, ensuring efficient passenger flow and high server utilization.

---

## Table of Contents
- [Features](#features)
- [Options Menu](#options-menu)
- [Installation and Running the Simulation](#installation-and-running-the-simulation)
- [Implementation Approach](#implementation-approach)
---

### Features

1. **Single Server, Infinite Buffer (M/M/1)**
2. **Single Server, Finite Buffer (M/M/1/K)**
3. **Multiple Servers, Infinite Buffer (M/M/m)**
4. **Multiple Servers, Finite Buffer (M/M/m/K)**

Each of these configurations can be selected from the **Options Menu** and tested with custom parameters for arrival rate, service rate, and buffer size.

---

### Options Menu

Upon starting the program, you can choose from the following options:

1. **Single Server with Infinite Buffer**: Simulates a single server system with an unlimited queue. The arrival rate and service rate can be specified.
2. **Single Server with Finite Buffer**: Simulates a single server system with a limited buffer size. You can specify the arrival rate, service rate, and buffer size.
3. **Multiple Servers with Infinite Buffer**: Simulates a system with multiple servers and an unlimited queue. You can specify the arrival rate, service rate, and the number of servers.
4. **Multiple Servers with Finite Buffer**: Simulates a system with multiple servers and a limited buffer. You can specify the arrival rate, service rate, number of servers, and buffer size.

---

### Installation and Running the Simulation

#### Prerequisites

- **C++ Compiler**: Ensure you have a C++ compiler that supports C++11 or higher.
- **Make**: For ease of compilation.

#### Steps to Run

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/ShivamGarg1106/Passenger-Recovery
   cd Passsenger-Recovery
   ```
2. **Compile the Code**:
    ```bash
    make
    ```
3. **Run the Simulation**:
    ```bash
    ./simulation
    ```
### Implementation Approach

The project simulates queuing models for airport security lines. Here’s a breakdown of the approach:

#### Queuing Theory Concepts

The simulation applies **queuing theory** to model passengers arriving and being processed at security checkpoints. The key components include:
- **Arrival Process**: Passengers arrive at the checkpoint based on an exponential distribution (Poisson process) governed by the arrival rate \( \lambda \).
- **Service Process**: Passengers are processed by a server based on a service rate \( \mu \), also following an exponential distribution.
- **Buffering**: The queue may have a finite or infinite capacity, representing whether or not it can accommodate an unlimited number of passengers.

#### Simulation Components

1. **Passenger Class**: Represents each passenger, including their unique ID, inter-arrival time, arrival time, and processing time.
2. **Single-Server and Multi-Server Systems**: Different functions manage the queue based on whether it’s a single-server or multi-server system.
3. **Infinite and Finite Buffers**: The buffer size determines whether passengers are added to the queue or dropped if the queue is full.
4. **Multithreading**: To handle arrivals and processing in parallel, the simulation uses multithreading. Separate threads are created for passenger arrivals and processing, allowing the system to realistically simulate simultaneous events and maintain accurate timing.
5. **Mutex for Thread Safety**: Mutexes are used to protect shared resources (like queues and counters) across threads, ensuring thread-safe operations. Each server has its own mutex, and a global mutex is applied to shared data, preventing race conditions during the arrival and service processes.
6. **Metrics Calculation**: Tracks waiting time, queue length, and server utilization by accumulating values across the simulation time. These metrics offer insights into performance for each configuration.

Each of these components plays a role in providing insights into system performance and optimizing passenger handling at airport security.


