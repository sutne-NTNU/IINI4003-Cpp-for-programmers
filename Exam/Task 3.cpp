#include<iostream>
#include<vector>
#include<thread>

using namespace std;


class ThreadSafeGrowingList {
private:
    vector<int> elements;
    mutex list_mutex;
public:
    ThreadSafeGrowingList() = default;

    void add(int element) {
        // make sure only one thread can add to list at a time to
        // prevent the threads overriding each other.
        lock_guard<mutex> lock(list_mutex);
        elements.emplace_back(element);
    }


    void for_each(const function<void(int)> &func) {
        // can only do it like this because we never remove elements from
        // the vector, we therefore don't have to worry about, going
        // outside the current memory for the vector
        for (size_t i = 0; i < elements.size(); i++) {
            func(elements[i]);
        }
    }
};


int main() {
    ThreadSafeGrowingList list;
    vector<thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back
                (
                        [&list, i] {
                            list.add(i);
                        }
                );
    }
    list.for_each([](int value) {
        cout << value << endl;
        this_thread::sleep_for(200ms);
    });
    for (auto &thread : threads)
        thread.join();
};