/*
In C++, a **callable object** is **anything that can be invoked using function-call syntax `()`**.

```cpp
callable();
```

This is a **very important concept**, especially for **threads, STL algorithms, callbacks, and modern C++ design**.

---

## 🔹 Simple Definition (Interview One-Liner)

> A callable object in C++ is an entity that can be called like a function using parentheses `()`.

---

## 🔹 Why Callable Objects Matter

Many C++ APIs accept **callables**, not just functions:

* `std::thread`
* `std::sort`
* `std::for_each`
* `std::async`
* Callbacks & event handlers

Example:

```cpp
std::thread t(callable);
```

---

## 🔶 Types of Callable Objects in C++

There are **5 main types** 👇

---

## 1️⃣ Normal (Free) Functions

```cpp
void foo() {
    std::cout << "Hello\n";
}

foo();  // callable
```

Used in:

```cpp
std::thread t(foo);
```

---

## 2️⃣ Lambda Expressions (Very Common)

```cpp
auto lambda = []() {
    std::cout << "Lambda called\n";
};

lambda();  // callable
```

Used in:

```cpp
std::thread t([]() {
    std::cout << "Thread lambda\n";
});
```

---

## 3️⃣ Function Objects (Functors)

A **class with `operator()` overloaded**.

```cpp
class Functor {
    public:
    void operator()() {
        std::cout << "Functor called\n";
    }
};

Functor f;
f();   // callable
```

Used when:

* You need **state**
* You want reusable logic

---

## 4️⃣ Member Functions (With Object)

Member functions are callable **through an object**.

```cpp
class Task {
    public:
    void run() {
        std::cout << "Member function\n";
    }
};

Task obj;
(obj.run)();  // conceptual
```

Used in threads like:

```cpp
std::thread t(&Task::run, &obj);
```

---

## 5️⃣ `std::function` (Type-Erased Callable)

A wrapper that can store **any callable**.

```cpp
#include <functional>

std::function<void()> f = []() {
    std::cout << "Stored callable\n";
};

f();  // callable
```

Used when:

* API should accept **any callable type**

---

## 🔹 Comparison Table (Interview Gold)

| Callable Type   | Stateful         | Fast | Flexible |
| --------------- | ---------------- | ---- | -------- |
| Function        | ❌                | ✅    | ❌        |
| Lambda          | ⚠️ (if captures) | ✅    | ✅        |
| Functor         | ✅                | ✅    | ⚠️       |
| Member function | ✅                | ✅    | ⚠️       |
| `std::function` | ✅                | ❌    | ✅        |

---

## 🔹 Callable Objects in `std::thread` (Key Use Case)

All of these are valid:

```cpp
std::thread t1(func);
std::thread t2([](){});
std::thread t3(Functor());
std::thread t4(&Class::method, &obj);
```

👉 **Thread accepts any callable**

---

## 🔹 Why Not Just Use Functions?

| Reason          | Callable Helps   |
| --------------- | ---------------- |
| Need state      | Functor / lambda |
| Generic API     | `std::function`  |
| Inline logic    | Lambda           |
| Object behavior | Member function  |

---

## 🧠 Interview One-Liners (Memorize)

* Callable object = anything invocable using `()`
* Lambdas and functors are callable objects
* `std::thread` accepts callable objects
* Functor = class with `operator()`

---

## 🔥 Common Follow-Up Questions

* Functor vs lambda?
* Why is `std::function` slower?
* How lambdas are implemented internally?
* Stateless vs stateful callable?
* Callable vs function pointer?

If you want, I can next explain:

* **Lambda capture in detail**
* **std::function internals**
* **Functor vs lambda vs function**
* **Real multithreading examples using callables**

Just tell me 👍

Below is a **deep but interview-friendly explanation** of all **5 topics**, with **clear comparisons, internals, and one-liners** you can directly use in interviews.

---

# 1️⃣ Functor vs Lambda

## 🔹 Functor

A **functor** is a **class with `operator()` overloaded**.

```cpp
class Add {
    int x;
public:
    Add(int v) : x(v) {}
    int operator()(int y) const {
        return x + y;
    }
};
```

## 🔹 Lambda

A **lambda** is a **compiler-generated functor** written using special syntax.

```cpp
int x = 10;
auto add = [x](int y) {
    return x + y;
};
```

### 🔑 Key Difference

| Aspect      | Functor | Lambda             |
| ----------- | ------- | ------------------ |
| Syntax      | Verbose | Compact            |
| Readability | Lower   | Higher             |
| State       | Yes     | Yes (via capture)  |
| Performance | Same    | Same               |
| Internals   | Manual  | Compiler-generated |

👉 **Internally, lambdas ARE functors**

### 🧠 Interview one-liner

> A lambda is just a syntactic shortcut for a compiler-generated functor.

---

# 2️⃣ Why is `std::function` Slower?

```cpp
std::function<int(int)> f = add;
```

### 🔹 Reason 1: Type Erasure

`std::function` hides the **actual callable type** behind a uniform interface.

* Compiler **cannot inline**
* Calls go through **virtual-like dispatch**

### 🔹 Reason 2: Heap Allocation (sometimes)

Large lambdas/functors may require **dynamic memory allocation**.

### 🔹 Reason 3: Indirection

Extra pointer dereferencing → slower than direct calls.

### 🔹 Performance Comparison

| Callable         | Speed   |
| ---------------- | ------- |
| Function pointer | Fast    |
| Lambda / functor | Fastest |
| `std::function`  | Slower  |

### 🧠 Interview one-liner

> `std::function` is slower because it uses type erasure, which prevents inlining and may involve heap allocation and indirect calls.

---

# 3️⃣ How Lambdas Are Implemented Internally?

### Example Lambda

```cpp
int x = 10;
auto lambda = [x](int y) {
    return x + y;
};
```

### 🔹 Compiler Converts It To (Conceptually):

```cpp
class __Lambda {
    int x;
public:
    __Lambda(int v) : x(v) {}
    int operator()(int y) const {
        return x + y;
    }
};
```

So this:

```cpp
lambda(5);
```

Becomes:

```cpp
__Lambda(x)(5);
```

### 🔑 Key Points

* Lambda = unnamed functor
* Captures become **member variables**
* `operator()` is generated automatically

### 🧠 Interview one-liner

> Lambdas are implemented as unnamed compiler-generated functor classes with captured variables stored as members.

---

# 4️⃣ Stateless vs Stateful Callable

## 🔹 Stateless Callable

No stored data.

```cpp
auto f = [](int a, int b) {
    return a + b;
};
```

* No captures
* No member variables
* Can decay to **function pointer**

```cpp
int (*fp)(int, int) = f;  // valid
```

---

## 🔹 Stateful Callable

Stores data internally.

```cpp
int x = 10;
auto f = [x](int y) {
    return x + y;
};
```

* Has internal state
* Cannot convert to function pointer
* Implemented as a class with members

---

### 🔑 Comparison

| Feature          | Stateless | Stateful    |
| ---------------- | --------- | ----------- |
| Captures         | ❌         | ✅           |
| Memory           | None      | Stores data |
| Function pointer | ✅         | ❌           |
| Performance      | Best      | Same        |

### 🧠 Interview one-liner

> Stateless callables have no stored data, while stateful callables store captured state inside the object.

---

# 5️⃣ Callable vs Function Pointer

## 🔹 Function Pointer

```cpp
void foo() {}

void (*fp)() = foo;
fp();
```

### Limitations:

* No state
* Only free functions
* Less flexible

---

## 🔹 Callable Object

```cpp
auto lambda = []() {
    std::cout << "Hello";
};

lambda();
```

### Advantages:

* Can store state
* Works with lambdas, functors, member functions
* Much more flexible

---

### 🔑 Comparison Table

| Feature          | Function Pointer | Callable |
| ---------------- | ---------------- | -------- |
| Stores state     | ❌                | ✅        |
| Lambdas          | ❌                | ✅        |
| Member functions | ❌                | ✅        |
| Performance      | Fast             | Fast     |
| Flexibility      | Low              | High     |

### 🧠 Interview one-liner

> A function pointer can only point to a function, while a callable object can encapsulate behavior and state.

---

# 🔥 Final Interview Summary (Memorize This)

> Lambdas are compiler-generated functors. `std::function` is slower due to type erasure and indirection. Stateless callables have no stored data and can decay to function pointers, while stateful callables store captured state. Callables are more flexible than function pointers because they can hold behavior and data together.

---

If you want next, I can:

* Explain **lambda capture modes (`=`, `&`, `this`)**
* Show **std::function vs template callable APIs**
* Explain **why thread accepts callables**
* Give **real interview Q&A drills**

Just tell me 👍

*/