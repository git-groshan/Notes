/* Implementation of a vector-like container in C++ without using STL */
/*
Below is a **clean, interview-quality implementation of `std::vector`-like container** **without using STL**,
written step-by-step so you can **explain every line** confidently.

This is exactly the kind of question asked in **C++ / system-level / telecom interviews**.

---

# 🔹 Requirements of a Vector

A vector must:

* Store elements in **contiguous memory**
* Support **dynamic resizing**
* Provide:

* `push_back`
* `pop_back`
* `operator[]`
* `size()`
* `capacity()`

---

# 🔹 Basic Vector Implementation (Template)

```cpp
*/
#include <iostream>
using namespace std;

template <typename T>
class MyVector {
private:
    T* data;          // Pointer to dynamic array
    int sz;           // Number of elements
    int cap;          // Allocated capacity

    void resize(int newCap) {
        T* newData = new T[newCap];

        for (int i = 0; i < sz; i++)
            newData[i] = data[i];

        delete[] data;
        data = newData;
        cap = newCap;
    }

public:
    // Constructor
    MyVector() {
        data = nullptr;
        sz = 0;
        cap = 0;
    }

    // Destructor
    ~MyVector() {
        delete[] data;
    }

    // push_back
    void push_back(const T& value) {
        if (sz == cap) {
            int newCap = (cap == 0) ? 1 : cap * 2;
            resize(newCap);
        }
        data[sz++] = value;
    }

    // pop_back
    void pop_back() {
        if (sz > 0)
            sz--;
    }

    // operator[]
    T& operator[](int index) {
        return data[index];  // No bounds check (same as std::vector)
    }

    // size
    int size() const {
        return sz;
    }

    // capacity
    int capacity() const {
        return cap;
    }

    // empty
    bool empty() const {
        return sz == 0;
    }
};
// ```

/*
---

# 🔹 Usage Example

```cpp
*/
int main() {
    MyVector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << "\nSize: " << v.size();
    cout << "\nCapacity: " << v.capacity();

    return 0;
}
// ```
/*
### Output:

```
10 20 30
Size: 3
Capacity: 4
```

---

# 🔹 Time Complexity (Important)

| Operation    | Complexity     |
| ------------ | -------------- |
| `push_back`  | O(1) amortized |
| `pop_back`   | O(1)           |
| `operator[]` | O(1)           |
| Resize       | O(n)           |

---

# 🔹 Why capacity doubles?

* Prevents frequent memory allocation
* Ensures **amortized O(1)** insertion

---

# 🔹 Interview Follow-Up Questions (With Answers)

### ❓ Why not increase capacity by 1?

> That would make `push_back` **O(n)** every time → bad performance.

---

### ❓ Why contiguous memory?

> Enables **cache-friendly access** and **random indexing**.

---

### ❓ Difference between `size` and `capacity`?

* **size** → elements stored
* **capacity** → memory allocated

---

# 🔹 Advanced Enhancements (If Interviewer Pushes)

### 1️⃣ Bounds-checked access

```cpp
*/
/*
T& at(int index) {
    if (index < 0 || index >= sz)
    throw out_of_range("Index out of range");
    return data[index];
}
```

### 2️⃣ Copy Constructor & Assignment (Rule of 3)

```cpp
MyVector(const MyVector& other) {
    sz = other.sz;
    cap = other.cap;
    data = new T[cap];
    for (int i = 0; i < sz; i++)
    data[i] = other.data[i];
}
```

---

# 🧠 One-Line Interview Summary

> A vector is implemented using a dynamically allocated contiguous array that grows geometrically, typically doubling capacity to achieve amortized constant time insertion.

---

If you want next, I can:

* Add **move semantics (Rule of 5)**
* Implement **iterator**
* Compare **vector vs list vs deque**
* Implement vector using **malloc/free (C-style)**

Just tell me 👍
*/
