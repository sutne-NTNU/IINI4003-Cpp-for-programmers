//
// Created by Sivert Utne on 09/10/2020.
//
#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

// formats vector to string when printing
ostream &operator<<(ostream &out, const vector<int> &table)
{
    for(auto &e : table)
        out << e << " ";
    return out;
}

// Returns the index of the element in the vector
int find_if_ValueOver(const vector<int> &table, int lowerLimit)
{
    auto pos = find_if(table.begin(), table.end(), [lowerLimit](int value) -> bool { return value > lowerLimit; });
    return pos - table.begin();
}

// Returns true if interval of table1 is equal to table2
bool approx_equal_interval(const vector<int> &table1, int nrOfElements, const vector<int> &table2)
{
    return equal(table1.begin(), table1.begin() + nrOfElements, table2.begin(), [](int number1, int number2) {
        return abs(number1 - number2) < 2;
    });
}

// replaces all odd numbers with the given value
vector<int> replace_oddNumbers(const vector<int> &table, int replaceWith)
{
    vector<int> replaced;
    replaced.resize(table.size());

    replace_copy_if(table.begin(), table.end(), replaced.begin(), [](int number) {
        return number % 2 != 0;
    }, replaceWith);
    return replaced;
}

int main()
{
    vector<int> vector_1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "vector_1: " << vector_1 << endl;
    vector<int> vector_2 = {2, 3, 12, 14, 24};
    cout << "vector_2: " << vector_2 << endl;

    // First element larger than 15
    int index_ValueOver = find_if_ValueOver(vector_1, 15);
    cout << "\nFirst element in vector_1 larger than 15 is: "
         << vector_1[index_ValueOver] << " at index " << index_ValueOver << endl;

    // Interval of vector_1 approximately equal to vector_2.
    bool equal = approx_equal_interval(vector_1, 5, vector_2);
    cout << "\nInterval [vector_1.begin(), vector_1.begin()+5> equal to vector_2? : " << boolalpha << equal << endl;
    equal = approx_equal_interval(vector_1, 4, vector_2);
    cout << "Interval [vector_1.begin(), vector_1.begin()+4> equal to vector_2? : " << boolalpha << equal << endl;

    // replacing odd numbers with 100
    vector<int> replaced = replace_oddNumbers(vector_1, 100);
    cout << "\nvector_1 after replacing odd numbers : " << replaced << endl;
}