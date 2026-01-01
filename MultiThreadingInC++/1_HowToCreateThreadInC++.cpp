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

// Requirement 
// find the addition of all odd number from 1 to 190000000 and all even number from 1 to 190000000
*/
#include <iostream>
#include <thread>

void printHello() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    std::thread t(printHello);
    t.join();
    return 0;
}