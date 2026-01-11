/*
Process : A process is an independent program in execution. It has its own memory space, code, data, and system resources.
Thread : A thread is a lightweight process that can run concurrently with other threads within the same program.
Also, Thread is a smaller unit of process sharing memory with other threads of the same process.

*/
// Topic: Introduction to Multi-threading in C++(C++11 and above)
// Subtopic: How to Create a Thread in C++
/*
There are 2 types of threads in C++ or any programming language:
1. User Threads - Created and managed by the programmer using C++ standard library.
2. Kernel Threads - Managed directly by the operating system.
Question: What is a thread in C++?
Answer: A thread in C++ is a separate path of execution within a program that can run
Question: How to create a thread in C++?
Answer: In C++, you can create a thread using the `<thread>` header from the C

Ques: What do you understand by thread and give one example of thread creation in C++?
Answer: A thread is a lightweight process that can run concurrently with other threads within the same program
a) In Every application there is a default thread which is main() in side this we create other threads.
b) A Thread a also known as lightweight process. Idea is achieve parallelism by dividing a process into multiple threads.
    For example: 
    1. The browser has multiple tabs that can be different threads 
    2. MS word must be using multiple threads,One thread to format the text,another thread to process the inputs(spell checker)
    3. VS code would be using threading for auto completing the code

Ways to create threads in C++11
1. Function Pointers 
2. Lambda Function 
3. Functors
4. Member Functions
5. Static Member Functions 

Requirement 
find the addition of all odd number from 1 to 190000000 and all even number from 1 to 190000000
*/

// A process is divided into multiple sub-processes called threads. Threads are also called lightweight processes.
// Each thread has its own stack, program counter, and registers but shares the same memory space with other threads in the same process.   

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;// for cout and endl
using namespace std::chrono; // for high_resolution_clock

void printHello() {
    std::cout << "Hello from thread!" << std::endl;
}
typedef unsigned long long ull;
ull oddSum = 0;
ull evenSum = 0;
//++ standard library.
void calculateOddSum(ull start, ull end) {
    for (ull i = start; i <= end; i++) {
        if (i % 2 != 0) {
            oddSum += i;
        }
    }
}
void calculateEvenSum(ull start, ull end) {
    for (ull i = start; i <= end; i++) {
        if (i % 2 == 0) {
            evenSum += i;
        }
    }
}

int main() {
    //Single Threaded Execution
    ull start = 1;
    ull end = 190000000;
    auto startTime = std::chrono::high_resolution_clock::now();
    calculateEvenSum(start, end);
    calculateOddSum(start, end);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    std::cout << "Single Threaded Execution Time: " << duration << " milliseconds" << std::endl;
    std::cout << "Even Sum: " << evenSum << std::endl;
    std::cout << "Odd Sum: " << oddSum << std::endl;
    // std::thread t(printHello);
    // t.join();
    //Multi Threaded Execution
    oddSum = 0; 
    evenSum = 0;
    startTime = std::chrono::high_resolution_clock::now();      
    //creating two threads using function pointers
    std::thread evenThread(calculateEvenSum, start, end);
    std::thread oddThread(calculateOddSum, start, end);
    evenThread.join();// wait for evenThread(process) to finish
    oddThread.join();// wait for oddThread to finish
    endTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    std::cout << "Multi Threaded Execution Time: " << duration << " milliseconds" << std::endl;
    std::cout << "Even Sum: " << evenSum << std::endl;
    std::cout << "Odd Sum: " << oddSum << std::endl;
    return 0;
}