//
// Created by Sivert Utne on 08/12/2020.
//
#include<iostream>
#include<vector>


using namespace std;


int main() {
    cout << "a)" << endl;
    {
        vector<int> v1 = {1, 2};
        vector<int> v2 = {3, 4};
        copy(v2.begin(), v2.end(), v1.begin() + 2);
        for (auto e : v1) {
            cout << e << endl;
        }
        /* Tries to copy the values from v2 to v1, but puts the elements outside of v1, so v1 doesn't change

         1
         2

         */
    }


    cout << "\n\nb)" << endl;
    {
        vector<int> v1 = {1, 2};
        vector<int> v2 = {3, 4};
        v1.insert(v1.end(), v2.begin(), v2.begin() + 1);
        for (auto e : v1) {
            cout << e << endl;
        }
        /* Tries insert the values from v2 to end of v1, but v2.begin()+1=3 is the last element to be inserted

         1
         2
         3

         */
    }


    cout << "\n\nc)" << endl;
    {
        vector<int> v1 = {1, 2, 3, 4};
        cout << *find_if(v1.begin(), v1.end(), [](int e) {
            return e > 2;
        }) << endl;
        /* prints first element the expression "e > 2" is true for:

         3

         */
    }


    cout << "\n\nd)" << endl;
    {
        vector<int> v1 = {1, 2};
        vector<int> v2 = {3, 4};
        cout << equal(v1.begin(), v1.end(), v2.begin(), [](int e1, int e2) {
            return e1 == e2 - 2;
        }) << endl;
        /* since all v1[i]=v2[i]+2, it prints "True"=1:

         1

         */
    }


    cout << "\n\ne)" << endl;
    {
        vector<int> v1 = {1, 2};
        vector<int> v2 = {3, 4};
        cout << equal(v2.begin(), v2.end(), v1.begin(), [](int e1, int e2) {
            return e1 == e2 + 2;
        }) << endl;
        /* since all v2[i]=v1[i]-2, it prints "True"=1:

         1

         */
    }
}
