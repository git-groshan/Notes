/*
Below is a **clear, interview-ready explanation** of **Thread**
and **Multithreading**, starting from basics → OS view → C++ view → examples → pros/cons.

---

## 🔹 What is a Thread?

A **thread** is the **smallest unit of execution** inside a process.

* A **process** can have **multiple threads**
* Threads in the same process:

* Share **memory (heap)**
* Share **code**
* Share **file descriptors**
* Each thread has its own:

* Stack
* Program counter
* Registers

### 👉 Simple definition (Interview one-liner)

> A thread is a lightweight execution unit within a process that runs independently.

---

## 🔹 What is Multithreading?

**Multithreading** is the ability of a program to **run multiple threads concurrently** to perform multiple tasks at the same time.

Example:

* One thread handles **UI**
* One thread handles **network**
* One thread handles **computation**

---

## 🔹 Process vs Thread (Very Important)

| Feature       | Process  | Thread                |
| ------------- | -------- | --------------------- |
| Memory        | Separate | Shared                |
| Creation cost | High     | Low                   |
| Communication | IPC      | Shared memory         |
| Crash impact  | Isolated | Affects whole process |

---

## 🔹 Why Multithreading is Used

✔ Better CPU utilization
✔ Improved performance
✔ Responsiveness
✔ Parallel execution on multi-core CPUs

Example:

```text
Single thread:  8 sec
Two threads:   ~4 sec
```

---

## 🔹 Real-World Example

### Web Browser

* Thread 1: UI rendering
* Thread 2: Page loading
* Thread 3: JavaScript execution

### 5G / Telecom Software

* Thread 1: UL processing
* Thread 2: DL processing
* Thread 3: Control plane signaling

---

## 🔹 Multithreading in C++ (Example)

```cpp
*/
#include <iostream>
#include <thread>

void task() {
  std::cout << "Running in a thread\n";
}

int main() {
    std::thread t(task);
    t.join();
    return 0;
}
// ```

// ---
/*
## 🔹 `join()` vs `detach()`

| Method     | Meaning                   |
| ---------- | ------------------------- |
| `join()`   | Main thread waits         |
| `detach()` | Thread runs independently |

```cpp
t.join();    // safe
t.detach(); // dangerous if misused
```

---

## 🔹 Types of Multithreading

1️⃣ **User-level threads**
2️⃣ **Kernel-level threads**
3️⃣ **Hybrid**

---

## 🔹 Common Multithreading Problems (Interview Gold)

| Problem            | Meaning                             |
| ------------------ | ----------------------------------- |
| Race condition     | Multiple threads modify shared data |
| Deadlock           | Threads wait forever                |
| Starvation         | Thread never gets CPU               |
| Data inconsistency | Unprotected shared access           |

---

## 🔹 How to Avoid Problems

✔ Mutex
✔ Lock guards
✔ Atomic variables
✔ Condition variables

Example:

```cpp
#include <mutex>
std::mutex m;
```

---

## 🧠 Interview One-Liners (Memorize)

* **Thread:** Smallest execution unit inside a process
* **Multithreading:** Running multiple threads concurrently
* Threads share memory, processes do not
* Multithreading improves performance but adds complexity

---

## 🔥 Typical Interview Follow-Ups

* What is race condition?
* What is deadlock?
* Thread vs process?
* join vs detach?
* Mutex vs semaphore?

If you want, I can next explain:

* **Mutex & lock_guard**
* **Race condition with example**
* **Deadlock scenarios**
* **Thread pool**
* **Multithreading in 5G systems**

Just tell me 👍
*/