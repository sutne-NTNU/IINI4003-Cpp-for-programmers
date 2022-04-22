#include<iostream>
#include<vector>

using namespace std;

/*
 * For printing the vectors
 */
ostream &operator<<(ostream &ostream, const vector<int> &v) {
    string elements;
    for (size_t i = 0; i < v.size(); ++i) {
        elements += to_string(v[i]);
        if (i != v.size() - 1)
            elements += ", ";
    }
    return ostream << "{" << elements << "}";
}


int main() {
    vector<int> vec = {1, 2, 3};

    vector<int> vecMultipliedBy2 = vec | Map([](int e) { return e * 2; });
    cout << vecMultipliedBy2 << endl;

    vector<int> vecFiltered = vec | Filter([](int e) { return e % 2 == 1; });
    cout << vecFiltered << endl;
};