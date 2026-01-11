/*
In **C++ (C++11 and later)**, there are **multiple ways to create a thread**, and this is a **very common interview question**.

Below is a **clean, interview-ready explanation with examples**, ordered from **most common → advanced**.

---

# 🔹 Ways to Create a Thread in C++

All methods use **`std::thread`**, but differ in **what you pass to it**.

---

## 1️⃣ Using a **Normal Function** (Most Common)

### Example

```cpp
*/
#include <iostream>
#include <thread>

void worker() {
    std::cout << "Thread running\n";
}

int main() {
    std::thread t(worker);
    t.join();
}
// ```

/*
### When to use

✔ Simple tasks
✔ Free functions

---

## 2️⃣ Using a **Lambda Function**

### Example

```cpp
*/
#include <thread>
#include <iostream>

int main() {
    std::thread t([]() {
        std::cout << "Thread using lambda\n";
    });
    t.join();
}
// ```

/*
### When to use

✔ Short logic
✔ No need for separate function

---

## 3️⃣ Using a **Function with Arguments**

### Example

```cpp
*/
#include <thread>
#include <iostream>

void print(int x, int y) {
    std::cout << x + y << "\n";
}

int main() {
    std::thread t(print, 10, 20);
    t.join();
}
// ```

/*
📌 Arguments are **copied by value** by default.

---

## 4️⃣ Using a **Member Function of a Class**

### Example

```cpp
*/
#include <thread>
#include <iostream>

class Task {
public:
    void run(int x) {
        std::cout << "Value: " << x << "\n";
    }
};

int main() {
    Task obj;
    std::thread t(&Task::run, &obj, 5);
    t.join();
}
// ```
/*

📌 Object pointer/reference must be passed.

---

## 5️⃣ Using a **Functor (Function Object)**

### Example

```cpp
*/
#include <thread>
#include <iostream>

class Functor {
public:
    void operator()() {
        std::cout << "Thread using functor\n";
    }
};

int main() {
    std::thread t(Functor{}); // use brace-initializer to avoid most-vexing-parse
    t.join();
}
// ```
/*
### When to use

✔ Stateful logic
✔ Reusable callable objects

---

## 6️⃣ Passing Arguments by Reference

### Example

```cpp
*/
#include <thread>
#include <iostream>

void increment(int& x) {
    x++;
}

int main() {
    int value = 10;
    std::thread t(increment, std::ref(value));
    t.join();
    std::cout << value; // 11
}
// ```
/*
📌 Use `std::ref()` to avoid copy.

---

## 🔹 Summary Table (Interview Gold)

| Method             | Example                              |
| ------------------ | ------------------------------------ |
| Normal function    | `std::thread t(func);`               |
| Lambda             | `std::thread t([]{});`               |
| Function with args | `std::thread t(func, a, b);`         |
| Member function    | `std::thread t(&Class::func, &obj);` |
| Functor            | `std::thread t(Functor());`          |
| Reference args     | `std::ref()`                         |

---

## 🧠 Interview One-Liner (Memorize)

> In C++, threads can be created using free functions, lambdas, functors, member functions, and functions with arguments via `std::thread`.

---

## 🔥 Common Follow-Up Questions

* Difference between **join** and **detach**
* What happens if a thread is not joined?
* What is **race condition**?
* Why use **thread pool**?
* `std::thread` vs `std::async`

If you want, I can next explain:

* Thread lifecycle
* Mutex & synchronization
* Real-world multithreading examples
* Thread safety in C++

Just tell me 👍
*/
