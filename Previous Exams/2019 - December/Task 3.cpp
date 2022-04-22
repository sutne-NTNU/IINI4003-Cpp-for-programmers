//
// Created by Sivert Utne on 08/12/2020.
//
#include<iostream>
#include<thread>
#include<memory> // for unique_ptr


void a() {
    std::thread *a_thread;
    {
        int a = 2;
        int *b = new int(2); // creates variable on the heap that doesn't get deleted automatically
        a_thread = new std::thread
                (
                        [&a, b] {
                            std::cout << (a + *b) << std::endl;
                        }
                );
    }
    // depending on the thread, the variable "a" might be deleted here, as the main program exits it's scope, before
    // "a_thread" has finished using it
    a_thread->join();
}


void b() {
    std::unique_ptr<std::thread> a_thread; // null pointer
    int a = 2;
    auto b = std::make_unique<int>(2);
    a_thread = std::make_unique<std::thread>
            (
                    [a, b = std::move(b)] {
                        std::cout << (a + *b) << std::endl;
                    }
            );
    a_thread->join();
}


int main() {
    a();
    b();
}
