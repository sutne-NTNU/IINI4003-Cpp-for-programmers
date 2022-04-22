//
// Created by Sivert Utne on 08/12/2020.
//
#include<vector>
#include<thread>
#include<iostream>
#include<map>


using namespace std;

long f(long x) {
    return x * 2;
}


int main() {
    map<long, long> results;  // problem was threads adding to results at the same time, overriding each other
    mutex results_mutex; // adding mutex for threads to use
    vector<thread> threads;
    for (long x = 43; x < 47; ++x) {
        threads.emplace_back
                (
                        [&results, &results_mutex, x] {
                            auto result = f(x); // Time-consuming task
                            // make threads wait in queue until mutex is unlocked
                            lock_guard<mutex> lock(results_mutex); // first thread in queue takes mutex and locks it
                            results.emplace(x, result);
                            // mutex is automatically unlocked when exiting the scope of the lock_guard to let
                            // next thread add its results
                        }
                );
    }
    for (auto &thread : threads)
        thread.join();
    for (auto &pair : results)
        cout << "f(" << pair.first << ") = " << pair.second << endl;
}
