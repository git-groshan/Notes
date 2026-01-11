/*
Great question — this shows you’re thinking at the **right level** for interviews 👍
Let’s answer it **precisely**, without confusion.

---

## Short Direct Answer (Interview One-Liner)

> **Yes.**
> In `std::thread evenThread(calculateEvenSum, start, end);`
> `calculateEvenSum` is passed as a **function pointer**, and `std::thread` uses it as a **callable object**.

---

## Now the Detailed Explanation (Important)

### Your code:

```cpp
std::thread evenThread(calculateEvenSum, start, end);
```

and

```cpp
void calculateEvenSum(ull start, ull end) {
    for (ull i = start; i <= end; i++) {
        if (i % 2 == 0) {
            evenSum += i;
        }
    }
}
```

---

## 🔹 What exactly is `calculateEvenSum` here?

`calculateEvenSum` is:

* A **free function**
* Its type is:

```cpp
void (*)(ull, ull)
  ```
* When passed to `std::thread`, it **decays to a function pointer**

So effectively, the call becomes:

```cpp
void (*fp)(ull, ull) = calculateEvenSum;
std::thread evenThread(fp, start, end);
```

---

## 🔹 Why is this allowed?

Because **function pointers are callable objects**.

Anything that can be invoked like:

```cpp
callable(args...);
```

is a callable.

And this works:

```cpp
fp(start, end);
```

So it satisfies the requirement.

---

## 🔹 What does `std::thread` actually do internally?

Conceptually:

```cpp
template <class Callable, class... Args>
thread(Callable&& f, Args&&... args) {
    // store f and args
    // start a new OS thread
    f(args...);  // executed inside new thread
}
```

In your case:

* `Callable` → function pointer
* `Args` → `start`, `end`

---

## 🔹 Is it *only* a function pointer?

👉 **No.**

`std::thread` is **callable-agnostic**.
It accepts **any callable**:

| Callable Type    | Example                           |
| ---------------- | --------------------------------- |
| Function pointer | `calculateEvenSum`                |
| Lambda           | `[](){}`                          |
| Functor          | `struct X { void operator()(); }` |
| Member function  | `&Class::method`                  |

Your case happens to be **function pointer**.

---

## 🔹 What it is NOT

❌ It is **not**:

* `std::function`
* A functor
* A lambda

It is **directly a function pointer**.

---

## 🔹 Interview Trap (Important)

### ❓ Is `calculateEvenSum` copied?

No.

* Only the **function address** is stored
* No copying of function code

---

## 🔹 One More Important Observation (Race Condition ⚠️)

Your code uses:

```cpp
evenSum += i;
```

If another thread also modifies `evenSum`, this is a **race condition**.

Correct approach:

```cpp
std::mutex m;

void calculateEvenSum(ull start, ull end) {
    ull localSum = 0;
    for (ull i = start; i <= end; i++) {
        if (i % 2 == 0) {
            localSum += i;
        }
    }
    std::lock_guard<std::mutex> lock(m);
    evenSum += localSum;
}
```

---

## 🔥 Final Interview-Ready Explanation (Memorize This)

> In this case, `calculateEvenSum` is a free function that decays to a function pointer. `std::thread` treats it as a callable object and invokes it in a new thread along with the provided arguments.

---

If you want next, I can:

* Rewrite this using **lambda**
* Rewrite using **functor**
* Explain **why thread copies arguments**
* Explain **how `std::thread` stores callables**

Just tell me 👍
*/