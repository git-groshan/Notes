/*
In C++, threads can be created using free functions, lambdas, functors, member functions, and functions with arguments via std::thread.
There are 5 different ways to create a thread in C++ using callable objects.
 This example demonstrates the use of a functor (a class with an overloaded operator()) to create a thread.
NOTe: 
1. If we create multiple thread at the same time it doesn't guarantee the order of execution of threads. It means thread created first may not execute first.
2. Functor is an object of a class that overloads the operator() to make it callable like a function.

*/
// Thread Using Function Pointer 
// If we want to pass argument to the thread function we can do it by passing the argument to the thread constructor after the function name.

#include <thread>
#include <iostream>

//Way1 to create thread using  Function Definition
// function must have void return type and can have any number of arguments
void fun(int x) {
    std::cout << "Thread using function pointer with arg: " << x << "\n";
    while (x--)
    {
        /* code */
        std::cout<<"Value of x is : "<<x<<std::endl;
    }
    
}
// way2 to create thread using  lambda Definition
auto lambda = [](int x) {
    std::cout << "Thread using lambda with arg: " << x << "\n";
    while (x--)
    {
        /* code */
        std::cout<<"Value of x is : "<<x<<std::endl;
    }
    
};
//way 3 to create thread using Functor Definition
// functor class is class with overloaded operator()
class Functor {
    public:
    // function must have void return type and can have any number of arguments
    void operator()(int x) {
        std::cout << "Thread using functor with arg: " << x << "\n";
        while (x--)
        {
            /* code */
            std::cout<<"Value of x is : "<<x<<std::endl;
        }
    }
};
//Way 4 : create thread using Non-static member function of a class 
class Base
{
    public:
    // function must have void return type and can have any number of arguments
    void run(int x)
    {
        std::cout << "Thread using non-static member function with arg: " << x << "\n";
        while (x--)
        {
            /* code */
            std::cout<<"Value of x is : "<<x<<std::endl;
        }
    }
    
};

// Way 5 : create thread using Static member function of a class
class StaticBase
{
    public:
    // function must have void return type and can have any number of arguments
    static void run(int x)
    {
        std::cout << "Thread using static member function with arg: " << x << "\n";
        while (x--)
        {
            /* code */
            std::cout<<"Value of x is : "<<x<<std::endl;
        }
    }
};





int main() {
    std::cout << "Main thread is running\n";
    // Creating threads using different callable objects
    // Way 1: Function Pointer
    std::thread functionPointerThread1(fun, 5); // Thread created using function pointer with argument
    std::thread functionPointerThread2(fun, 11); // Thread created using function pointer with argument

    // Way 2: Lambda Function
    std::thread lambdaThread(lambda, 7); // Thread created using lambda with argument

    // Way 3: Functor
    std::thread functorThread(Functor{}); //Thread created using functor (use brace-initializer to avoid most-vexing-parse)

    // Way 4: Non-static member function of a class
    Base obj;// create object of Base class
    std::thread memberFunctionThread(&Base::run, &obj, 9); // Thread created using non-static member function with argument

    // Way 5: Static member function of a class
    std::thread staticMemberFunctionThread(&StaticBase::run, 6); // Thread created using static member function with argument

    // Wait for all threads to finish
    functionPointerThread1.join();// wait for functionPointerThread1 to finish
    functionPointerThread2.join();// wait for functionPointerThread2 to finish
    lambdaThread.join(); // wait for lambdaThread to finish
    functorThread.join();// wait for functorThread to finish
    memberFunctionThread.join(); // wait for memberFunctionThread to finish
    staticMemberFunctionThread.join(); // wait for staticMemberFunctionThread to finish
    return 0;
}