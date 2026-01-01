/*
**Multithreading** is a programming technique where **multiple threads run concurrently within a single process** to perform tasks **in parallel or quasi-parallel**,
improving **performance, responsiveness, and CPU utilization**.

---

## Simple definition (interview-ready)

> **Multithreading allows a program to execute multiple threads simultaneously, 
sharing the same memory space but performing different tasks.**

---

## What is a Thread?

* A **thread** is the **smallest unit of execution**
* Multiple threads:

* Share **same code, heap, and global data**
* Have **separate stacks**

---

## Why multithreading is needed

* Better **CPU core utilization**
* Faster execution for **CPU-intensive tasks**
* Improved **responsiveness** (UI, network, I/O)
* Overlap **I/O wait** and computation

---

## Real-world analogy

👨‍🍳 **Kitchen example**

* One chef doing everything → slow
* Multiple chefs:

* One cuts vegetables
* One cooks
* One plates food
👉 Work finishes faster

---

## Multithreading example in **C++**

```cpp
*/
#include <iostream>
#include <thread>
#include<bits/stdc++.h>
using namespace std;

void task1() {
    cout << "Task 1 running\n";
}

void task2() {
    cout << "Task 2 running\n";
}

int main() {
    thread t1(task1);
    thread t2(task2);

    t1.join();   // wait for t1
    t2.join();   // wait for t2
}
// ```
/*
---

## Key multithreading concepts

| Concept        | Meaning                             |
| -------------- | ----------------------------------- |
| Thread         | Lightweight execution unit          |
| Concurrency    | Multiple tasks in progress          |
| Parallelism    | Tasks run at same time (multi-core) |
| Race condition | Threads access shared data unsafely |
| Mutex          | Prevents data corruption            |
| Deadlock       | Threads wait forever                |
| Context switch | CPU switches threads                |

---

## Multithreading vs Multiprocessing

| Feature      | Multithreading       | Multiprocessing |
| ------------ | -------------------- | --------------- |
| Memory       | Shared               | Separate        |
| Speed        | Faster communication | Slower          |
| Isolation    | Low                  | High            |
| Crash impact | Whole process        | Isolated        |

---

## Where multithreading is used

* Web servers (handle multiple clients)
* Telecom systems (like **5G CU/DU processing**)
* Game engines
* Databases
* OS schedulers

---

## Important interview note

* Multithreading **does not always mean faster**
* Poor synchronization can cause:

* Race conditions
* Deadlocks
* Performance degradation

---

## One-line takeaway

> **Multithreading improves performance by executing multiple threads concurrently within a single process while sharing memory.**

If you want next:

* mutex & condition variable explanation
* multithreading with lambda
* real telecom (5G CU) multithreading example
* common bugs & how to debug them

Just tell me 👍
*/
