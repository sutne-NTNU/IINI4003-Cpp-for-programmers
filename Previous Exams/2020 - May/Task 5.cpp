//
// Created by Sivert Utne on 08/12/2020.
//
#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

/**
 * Reverse order
 */
void a(vector<int> vec) {

    reverse(vec.begin(), vec.end());

    cout << "a)" << endl;
    for (auto &e : vec)
        cout << e << endl;
}

/**
 * Rotate 1 element from the front to the back
 */
void b(vector<int> vec) {

    rotate(vec.begin(), vec.begin() + 1, vec.end());

    cout << endl << "b)" << endl;
    for (auto &e : vec)
        cout << e << endl;

}

/**
 * Multiply each element with 2
 */
void c(vector<int> vec) {

    transform(vec.begin(), vec.end(), vec.begin(), [](int element) { return element * 2; });

    cout << endl << "c)" << endl;
    for (auto &e : vec)
        cout << e << endl;

}


int main() {
    vector<int> vec = {2, 5, 2, 5, 1, 5, 1};
    a(vec);
    b(vec);
    c(vec);
}