/*
Great question! Your multithreaded code is actually **slower** than single-threaded. This is a common issue in multithreading. Here's why:

## Reasons Multithreading is Slower Here:

### 1. **Thread Creation Overhead**
Creating and destroying threads takes time (context switching, memory allocation, OS scheduling). For small tasks, this overhead can exceed the actual work being done.

### 2. **Task is Too Simple**
Calculating sum in a loop is **extremely fast** - it's just addition operations. The thread overhead costs more than the computation itself.

### 3. **Cache Issues**
- Single thread: Data stays in CPU cache (very fast)
- Multiple threads: Cache misses, data bouncing between CPU cores (slower)

### 4. **Small Dataset**
Your range seems relatively small. Multithreading benefits become visible only with **large workloads**.

## When Does Multithreading Help?

Multithreading is beneficial when:
- **CPU-intensive** tasks (complex calculations, image processing, encryption)
- **Large datasets** (millions/billions of operations)
- **I/O-bound** operations (file reading, network calls - where threads wait)
- Task execution time >> thread creation overhead

## How to See Multithreading Benefits:

Try increasing your workload significantly:

```cpp
// Instead of calculating to 'end', try a MUCH larger range
long long start = 0;
long long end = 1900000000;  // Much larger!

// Or add more complex calculations
void calculateEvenSum(long long start, long long end) {
    for (long long i = start; i <= end; i++) {
        if (i % 2 == 0) {
            evenSum += i;
            // Add some computation to make it heavier
            for(int j = 0; j < 100; j++) {
                evenSum += sqrt(i);  // More CPU work
            }
        }
    }
}
```

## Example: When Multithreading Shines

```cpp
// Heavy computation example
void complexCalculation(int start, int end) {
    for(int i = start; i < end; i++) {
        // Simulate heavy work
        double result = 0;
        for(int j = 0; j < 10000; j++) {
            result += sqrt(i * j) * sin(i) * cos(j);
        }
    }
}
```

With this heavier workload, you'll see multithreading become **significantly faster**.

## Your Current Results Explained:

```
Single Thread: 452ms (pure computation)
Multi Thread:  529ms (computation + thread overhead)
```

The **77ms difference** is the cost of creating 2 threads, context switching, and synchronization - which outweighs the benefit of parallel computation for this simple task.

**Rule of thumb**: Only use multithreading when each thread has enough work to do (typically milliseconds to seconds of computation per thread).
*/