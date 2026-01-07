/*
Below is a **clear, detailed, interview-oriented explanation of Templates in C++**,
starting from basics → types → internals → pitfalls → real examples.

---

# 🔷 What is a Template in C++?

A **template** is a mechanism in C++ that allows you to write **generic (type-independent) code**.

Instead of writing the **same logic for different data types**, 
you write it **once**, and the compiler generates type-specific code automatically.

👉 **Templates enable compile-time polymorphism.**

---

## 🔹 Why Templates are Needed (Motivation)

Without templates:

```cpp
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
```

👉 Code duplication ❌

With templates:

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

👉 One function for all types ✅

---

# 🔶 Types of Templates in C++

## 1️⃣ Function Templates

### Example

```cpp
*/
#include <iostream>
using namespace std;

template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << maximum(10, 20) << endl;      // int
    cout << maximum(3.5, 2.1) << endl;    // double
}
// ```
/*
### What happens internally?

* Compiler generates:

```cpp
*/
  int maximum(int, int);
  double maximum(double, double);
//   ```
/*
* This process is called **template instantiation**.

---

## 2️⃣ Class Templates

Used when **entire class depends on a data type**.

### Example

```cpp
*/
template <typename T>
class Box {
private:
    T value;

public:
    Box(T v) : value(v) {}

    T getValue() {
        return value;
    }
};

int main() {
    Box<int> b1(10);
    Box<string> b2("Hello");

    cout << b1.getValue() << endl;
    cout << b2.getValue() << endl;
}
// ```
/*
---

## 3️⃣ Multiple Template Parameters

```cpp
*/
template <typename T, typename U>
class Pair {
public:
    T first;
    U second;

    Pair(T a, U b) : first(a), second(b) {}
};
// ```
/*
Usage:

```cpp
*/
Pair<int, double> p(10, 3.14);
// ```
/*
---

## 4️⃣ Template Specialization

Used when **generic logic doesn’t work for a specific type**.

### Example

```cpp
*/
template <typename T>
class Printer {
public:
    void print(T val) {
        cout << val << endl;
    }
};

// Specialization for char*
template <>
class Printer<char*> {
public:
    void print(char* val) {
        cout << "String: " << val << endl;
    }
};
// ```
/*
---

## 5️⃣ Non-Type Template Parameters

Template parameters can be **values**, not just types.

```cpp
*/
template <int N>
class Array {
private:
    int arr[N];

public:
    int size() const { return N; }
};
// ```
/*
Usage:

```cpp
*/
Array<10> a;   // Size known at compile time
// ```
/*
---

# 🔶 `typename` vs `class`

```cpp
template <typename T>
```

and

```cpp
template <class T>
```

✔ Both are **identical**
✔ `typename` is preferred for clarity

---

# 🔶 Compile-Time Polymorphism vs Runtime

| Feature     | Templates    | Virtual Functions |
| ----------- | ------------ | ----------------- |
| Binding     | Compile-time | Runtime           |
| Overhead    | None         | Vtable lookup     |
| Flexibility | Less         | More              |

---

# 🔶 Common Template Pitfalls (Interview Important)

### ❌ Code Bloat

* Each type creates a new function/class
* Increases binary size

### ❌ Poor Error Messages

* Template errors are long and complex

### ❌ Must be Visible at Compile Time

Templates must be implemented in **header files**.

---

# 🔶 Real-World Usage

Templates power the **entire STL**:

* `vector<T>`
* `map<K, V>`
* `pair<T, U>`

Example:

```cpp
vector<int> v;
vector<double> d;
```

---

# 🧠 One-Line Interview Definition

> A template in C++ allows writing generic, 
reusable code that works with any data type and is resolved at compile time.

---

# 🔥 Interview Follow-Up Questions You May Get

* Difference between **template and macro**
* What is **template instantiation**
* What is **SFINAE**
* What are **variadic templates**
* Why templates cause code bloat
* When to use template vs inheritance

If you want, I can next:

* Explain **templates vs macros**
* Show **STL vector implementation using templates**
* Explain **variadic templates with examples**
* Give **template interview Q&A**

Just tell me 👍

*/