# Smart Traffic Signal Queue Simulator Using Linked List

## Project overview
This is a menu-driven C++ console project that simulates vehicles waiting at a red traffic signal. It uses a **singly linked list** to implement a **FIFO (First In, First Out) queue**.

When the signal turns green, the vehicle at the front is allowed to pass first.

## Data structure used
Each linked-list node stores:
- Token number
- Vehicle number
- Vehicle type
- Pointer to the next vehicle

The queue maintains two pointers:
- `front`: the first vehicle waiting
- `rear`: the last vehicle waiting

## Features
1. Add an arriving vehicle (Enqueue)
2. Let the first vehicle pass (Dequeue)
3. Display the waiting queue
4. Search for a vehicle by registration number
5. Count waiting vehicles
6. Check whether the queue is empty

## Queue principle
**FIFO = First In, First Out.** The vehicle that arrives first passes first.

Example:

```text
FRONT -> [Car] -> [Bike] -> [Bus] <- REAR
```

After one vehicle passes:

```text
FRONT -> [Bike] -> [Bus] <- REAR
```

## How to compile and run

### Option 1: Using g++
1. Install a C++ compiler such as g++.
2. Open a terminal in this project folder.
3. Compile:

```bash
g++ main.cpp -o traffic_queue
```

4. Run on Windows:

```bash
traffic_queue.exe
```

On macOS/Linux:

```bash
./traffic_queue
```

### Option 2: Using Dev-C++
1. Open Dev-C++.
2. Select **File → New → Source File**.
3. Copy the code from `main.cpp` and paste it.
4. Save as `main.cpp`.
5. Click **Execute → Compile & Run** (or press F11, depending on your version).

## Sample workflow
1. Select `1` and add `MH12AB1234`, type `Car`.
2. Select `1` and add `MH12XY5678`, type `Bike`.
3. Select `3` to view the queue.
4. Select `2` when the signal turns green. The first vehicle passes.
5. Select `3` again to see the updated queue.

## Complexity
Let `n` be the number of vehicles waiting:
- Add vehicle (enqueue): **O(1)**
- Vehicle passes (dequeue): **O(1)**
- Display queue: **O(n)**
- Search vehicle: **O(n)**
- Count vehicles: **O(n)**

## Limitations
This is an educational console simulation, not a live traffic-control system. It does not connect to real traffic lights, sensors, cameras, or emergency-service systems.

## Author
Add your name and class details here.
