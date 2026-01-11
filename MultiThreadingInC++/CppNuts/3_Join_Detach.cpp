/*
#########  Join vs Detach in C++ Threads #########
In C++, when working with threads, you have two primary options for managing the lifecycle of a thread: join and detach. 
Both methods serve different purposes and have distinct implications for thread management.
1. std::thread::join():
- Purpose: The join method is used to wait for a thread to finish its execution.
- Behavior: When a thread is joined, the calling thread (usually the main thread) will block and wait until the joined thread completes its task. 
            This ensures that the resources associated with the thread are properly cleaned up.
- Usage: Join is useful when you need to ensure that a thread has completed its work before proceeding, especially when the main thread depends on the results of the joined thread.
- Caution: Failing to join a thread before the main thread exits can lead to undefined behavior, as the thread may still be running when the program terminates.


2. std::thread::detach():
- Purpose: The detach method is used to allow a thread to run independently without waiting for it.
- Behavior: When a thread is detached, it continues to run in the background even after the main thread has finished executing. 
            The resources associated with the detached thread are automatically released when the thread completes its execution.
- Usage: Detach is useful when you want to start a thread that performs a task independently and you do not need to synchronize with it later.
- Caution: Detached threads can lead to resource management issues if not handled carefully, as there is no way to join or check the status of a detached thread.
### Example Code Demonstrating Join and Detach ###
```cpp  
*/
/*
    JOIN NOTES:-
    1. When you call join() on a thread, the calling thread will block until the joined thread completes its execution.
    2. Joining a thread ensures that the resources associated with the thread are properly cleaned up
    3. Failing to join a thread before the main thread exits can lead to undefined behavior, as the thread may still be running when the program terminates.
    4. You can only join a thread once. Attempting to join a thread that has already been joined or detached will result in a runtime error.
    5. Joining a thread is a way to synchronize the completion of threads, ensuring that the main thread waits for the joined thread to finish before proceeding.
    6. Join is useful when you need to ensure that a thread has completed its work before proceeding, especially when the main thread depends on the results of the joined thread.
    7. if needed we should check thread joinable() before calling join() to avoid runtime errors.
    8. Joining a thread is a blocking operation, meaning the calling thread will wait until the joined thread completes its execution.
    9. Joining a thread is essential for proper resource management, as it ensures that the resources associated with the thread are released when the thread finishes.
    10. If a thread is not joined and the main function returns, it may lead to undefined behavior.
    11. Joining a thread is important to avoid resource leaks, as the resources associated with a thread are not automatically released until the thread is joined.



    DETACH NOTES:-  This is used to detach newly created thread from main thread or parent thread.
    1. When you call detach() on a thread, the thread continues to run independently in the background.
    2. Detaching a thread allows it to run without blocking the calling thread.
    3. The resources associated with a detached thread are automatically released when the thread completes its execution.
    4. Detached threads can lead to resource management issues if not handled carefully, as there is no way to join or check the status of a detached thread.
    5. Detaching a thread is useful when you want to start a thread that performs a task independently and you do not need to synchronize with it later.
    6. Once a thread is detached, there is no way to join it or check its status, so you must ensure that the thread's work is completed before the program exits.
    7. Detach is useful for fire-and-forget tasks where you do not need to wait for the thread to finish.
    8. if the main thread exits before the detached thread completes its execution, the detached thread may be terminated prematurely.
    9. Detached threads should be used with caution, especially when dealing with shared resources, to avoid race conditions and undefined behavior.
    10. It is important to ensure that any resources used by the detached thread remain valid for the duration of its execution.
    11. Detached threads are often used for background tasks that do not require synchronization with the main thread.
    12. Detach is useful when you want to start a thread that performs a task independently and you do not need to synchronize with it later.
    13. Always check if a thread is joinable() before calling detach() to avoid runtime errors. Or we may double detach a thread leading to program crash.
    13. if we have main thread exiting before detached thread completes its execution, it may lead to undefined behavior.
    14. If we have detached thread an main function is returning then the detached thread may not complete its execution leading to incomplete tasks.
    15. If a thread is detached and the main function returns, the detached thread may not complete its execution leading to incomplete tasks.
### IMPORTANT NOTE ###
    1. Always check if a thread is joinable() before calling detach() to avoid runtime errors.
    2. If a thread is detached and the main function returns, the detached thread may not complete its execution leading to incomplete tasks.
    3. Detaching a thread that accesses shared resources can lead to race conditions and undefined behavior if not handled carefully.
    4. Detached threads should be used with caution, especially when dealing with shared resources, to avoid race conditions and undefined behavior.
    5. Either join() or detach() a thread before the thread object goes out of scope to avoid std::terminate being called. Because  during thread objects's destructor it checks  if the thread is still joinable then std::terminate will be called leading to program crash.
*/
#include <iostream>
#include <thread>
#include <chrono>

void threadFunctionJoin() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread with join completed.\n";
}
void threadFunctionDetach() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Thread with detach completed.\n";
}

void runThreads() {
    // Creating a thread that will be joined
    std::thread joinThread(threadFunctionJoin);
    
    // Creating a thread that will be detached
    std::thread detachThread(threadFunctionDetach);
    detachThread.detach(); // Detaching the thread

    // Joining the joinThread to wait for its completion
    joinThread.join();
    std::cout << "Main thread completed after joining.\n";
}

void run(int count)
{
    while(count --> 0)
    {   
        std::cout << "Thread using join/detach example, count: " << count << "\n";
    }
    std::cout << "Thread using join/detach example completed.\n";
    std::cout << "Exiting thread after a short delay...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "Thread exiting now.\n";
}

int main() {
    runThreads();
    // Giving some time for the detached thread to complete before main exits
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::thread t1(run, 5);
    t1.join(); // Joining the thread
    // t1.join(); // Joining again to show that joining twice will cause runtime error
    if(t1.joinable())
    {
        t1.join(); // Safe to join
    }
    /*
        Sample Output with join example:
        Thread with join completed.
        Main thread completed after joining.
        Thread with detach completed.
        Thread using join/detach example, count: 4
        Thread using join/detach example, count: 3
        Thread using join/detach example, count: 2
        Thread using join/detach example, count: 1
        Thread using join/detach example, count: 0
        Thread using join/detach example completed.
        Exiting thread after a short delay...
        Thread exiting now.
    */
    
    std::thread t2(run, 5);
    t2.detach(); // Detaching the thread
    // t2.detach(); // Detaching again to show that detaching twice will cause runtime error
    if(t2.joinable())
    {
        t2.detach(); // Safe to detach
    }
    return 0;
}