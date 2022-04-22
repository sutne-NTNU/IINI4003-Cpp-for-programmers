#include <vector>
#include <iostream>


using namespace std;

int main() {
    vector<double> numbers;
    for (int i = 0; i < 5; i++) {
        numbers.emplace_back(i + 1.01);
    }

    cout << "front(): " << numbers.front() << endl; // 	front(): 1.01
    cout << "back(): " << numbers.back() << endl;  //back() 5.01

    numbers.emplace(numbers.begin() + 1, 6.99);
    cout << "front() after emplace: " << numbers.front() << endl; // front() after emplace: 1.01

    vector<double>::iterator it;
    it = find(numbers.begin(), numbers.end(), 6.99);
    if (it != numbers.end())
        cout << "Element found: " << *it << endl; // Element found: 6.99
    else
        cout << "Element not found" << endl;

    cout << "Elements in vector: ";
    for (auto &number : numbers) {
        cout << number << " "; // Elements in vector: 1.01 6.99 2.01 3.01 4.01 5.01
    }
    cout << endl;
}

