/*Here’s **one compact but complete C++ example** that explains **almost every important concept of lambda expressions** in a **single program** — this is **interview-ready** and practical.

---

## ✅ Complete Lambda Expression Example (C++11+)

```cpp
*/
/* Capture list syntax:
[ ]   // capture nothing
[=]   // capture all by value
[&]   // capture all by reference
[x]   // capture x by value
[&x]  // capture x by reference
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int x = 10;
    int y = 5;

    // 1️⃣ Basic lambda (no capture)
    auto add = [](int a, int b) {
        return a + b;
    };
    cout << "Add: " << add(3, 4) << endl;

    // 2️⃣ Capture by VALUE
    auto byValue = [x]() {
        // x++; ❌ Not allowed (read-only)
        return x + 1;
    };
    cout << "Capture by value: " << byValue() << endl;

    // 3️⃣ Capture by REFERENCE
    auto byRef = [&y]() {
        y += 10;
    };
    byRef();
    cout << "Capture by reference (y): " << y << endl;

    // 4️⃣ Mixed capture
    auto mixed = [=, &y]() {
        // x is by value, y is by reference
        return x + y;
    };
    cout << "Mixed capture: " << mixed() << endl;

    // 5️⃣ Mutable lambda
    auto mutableLambda = [x]() mutable {
        x += 5;
        return x;
    };
    cout << "Mutable lambda: " << mutableLambda() << endl;
    cout << "Original x still: " << x << endl;

    // 6️⃣ Lambda as function argument (STL)
    vector<int> v = {5, 2, 8, 1};

    sort(v.begin(), v.end(), [](int a, int b) {
        return a < b;
    });

    cout << "Sorted vector: ";
    for (int n : v) cout << n << " ";
    cout << endl;

    // 7️⃣ Lambda returning void
    auto printer = [](int n) {
        cout << "Value: " << n << endl;
    };
    printer(100);

    // 8️⃣ Lambda with auto parameters (C++14+)
    auto generic = [](auto a, auto b) {
        return a + b;
    };
    cout << "Generic lambda: " << generic(2, 3.5) << endl;

    return 0;
}
// ```

/*
---

## 🔍 What this ONE example covers

| Concept               | Where shown        |
| --------------------- | ------------------ |
| Anonymous function    | `[](int a, int b)` |
| No capture            | `add`              |
| Capture by value      | `[x]`              |
| Capture by reference  | `[&y]`             |
| Mixed capture         | `[=, &y]`          |
| `mutable` keyword     | `mutableLambda`    |
| Lambda as argument    | `sort()`           |
| Return type deduction | everywhere         |
| `auto` parameters     | `generic` (C++14)  |
| Short & inline logic  | entire example     |

| Feature     | Lambda               | Normal Function          |
| ----------- | -------------------- | ------------------------ |
| Name        | Anonymous            | Named                    |
| Size        | Short                | Can be long              |
| Use case    | One-line logic       | Reusable logic           |
| Readability | High for small logic | Better for complex logic |


---

## 🧠 Key interview takeaways

* Lambda is **syntactic sugar for a functor**
* Capture list controls **scope access**
* `mutable` allows modification of **captured-by-value**
* Lambdas are heavily used in **STL, callbacks, threads**

---

## ⚡ One-line interview definition

> **A lambda expression in C++ is an anonymous function that can capture variables from its surrounding scope and is commonly used for short, inline logic.**

If you want, I can also provide:

* ❓ **lambda vs function pointer**
* 🧵 **lambda in multithreading**
* 🧬 **how compiler converts lambda internally**
* 🧪 **common mistakes in lambdas**

Just say the word 👍
*/