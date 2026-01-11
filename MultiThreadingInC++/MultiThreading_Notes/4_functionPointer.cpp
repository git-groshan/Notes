/*
Below is a **clear, interview-ready explanation** of **function pointers**, their **use cases**, and **how they are used with threads**, with simple examples and one-liners you can memorize.

---

# 🔹 What is a Function Pointer?

A **function pointer** is a variable that **stores the address of a function** and can be used to **call that function indirectly**.

### Simple definition (Interview one-liner)

> A function pointer is a pointer that points to a function and allows calling the function dynamically.

---

## 🔹 Basic Syntax

```cpp
*/
// return_type (*pointer_name)(parameter_types);
// ```

// ### Example

// ```cpp
#include <iostream>
using namespace std;

void greet() {
    cout << "Hello\n";
}

int main() {
    void (*fp)() = greet;  // function pointer
    fp();                 // calls greet()
}
// ```

// ---

/*
## 🔹 Why Do We Need Function Pointers?

### 1️⃣ Runtime behavior selection

Choose which function to run **at runtime**.

```cpp
*/
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int main() {
    int (*op)(int, int);
    op = add;
    cout << op(5, 3);
}
// ```

// ---
/*
### 2️⃣ Callbacks (Very Important Use Case)

Used when one module calls a function **provided by another module**.

Example:

* OS callbacks
* Event handlers
* Networking libraries
* Legacy C APIs

```cpp
*/
void onEvent() {
    cout << "Event occurred\n";
}

void registerCallback(void (*cb)()) {
    cb();
}
// ```
/*
---

### 3️⃣ Strategy pattern (without OOP)

Replace `if-else` or `switch`.

---
*/

/*
### 4️⃣ C compatibility

C language **does not have lambdas or functors**, so function pointers are essential.

---

## 🔹 Function Pointer vs Normal Function Call

| Feature     | Normal Call  | Function Pointer |
| ----------- | ------------ | ---------------- |
| Binding     | Compile-time | Runtime          |
| Flexibility | Low          | High             |
| Overhead    | None         | Very small       |

---

# 🔹 How Function Pointers Are Used in Threads

`std::thread` accepts **any callable object**, and a **function pointer is a callable**.

---

## ✅ Thread Using Function Pointer (Simple)

```cpp
*/
#include <iostream>
#include <thread>
using namespace std;

void task() {
    cout << "Thread running\n";
}

int main() {
    void (*fp)() = task;

    thread t(fp);  // function pointer passed
    t.join();
}
// ```

/*
✔ Works because function pointers are callable.

---

## 🔹 Thread with Function Pointer + Arguments

```cpp
*/
#include <thread>
#include <iostream>
using namespace std;

void sum(int a, int b) {
    cout << a + b << endl;
}

int main() {
    void (*fp)(int, int) = sum;

    thread t(fp, 10, 20);
    t.join();
}
// ```

// ---
/*
## 🔹 Important Rules (Interview Gold)

### ❗ Function pointer must match signature

```cpp
*/
void foo(int);
void (*fp)() = foo;  // ❌ ERROR
// ```

// ---
/*
### ❗ Function pointer cannot store state

```cpp
*/
int x = 10;
void foo() { cout << x; }  // uses global only
// ```

/*
✔ No captured variables (unlike lambdas)

---

# 🔹 Function Pointer vs Lambda vs Functor (Quick)

| Feature      | Function Pointer | Lambda | Functor |
| ------------ | ---------------- | ------ | ------- |
| Stores state | ❌                | ✅      | ✅       |
| Syntax       | Verbose          | Clean  | Verbose |
| Performance  | Fast             | Fast   | Fast    |
| Thread use   | ✅                | ✅      | ✅       |

---

## 🔹 Why Lambdas Are Preferred Today

* Can capture variables
* Cleaner syntax
* Same performance
* Safer design

But…

👉 **Function pointers are still important** for:

* Legacy code
* C APIs
* Low-level systems
* OS callbacks

---

## 🧠 Final Interview One-Liners (Memorize)

* A function pointer stores the address of a function.
* It enables runtime function selection and callbacks.
* `std::thread` can execute a function via a function pointer.
* Function pointers cannot store state, unlike lambdas or functors.

---

If you want next, I can:

* Compare **function pointer vs `std::function`**
* Explain **callbacks in real systems**
* Show **thread bugs with function pointers**
* Explain **member function pointers**

Just tell me 👍
*/