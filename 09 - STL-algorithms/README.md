# STL - algorithms
In this assignment you will need several STL-algorithms that weren't in the lecture. You can use the STL-references at http://www.cplusplus.com/reference/algorithm or https://en.cppreference.com/w/cpp/algorithm

Use the vectors v1 and v2 from the lecture. One of the arguments in  the algorithms you use (find_if, equal, replace_copy_if) should be an anonymous function.
- Find the first element in v1 that is larger than 15 by using **find_if**.

- We define "approximately equal" to mean that the difference between two values is less than 2. Check if the interval **[v1.begin(), v1.begin() + 5>** and **v2** are equal with this definition. What about **[v1.begin(), v1.begin() + 4>**? Use the algorithm **equal**.

- Replace all odd numbers in v1 with 100 by using **replace_copy_if**.

## Result
### Finding first element over 15
```c++
// Returns the index of the element in the vector
int find_if_ValueOver(const vector<int> &table, int lowerLimit)
{
    auto pos = find_if(table.begin(), table.end(), [lowerLimit](int value) -> bool { return value > lowerLimit; });
    return pos - table.begin();
}

int main(){
    vector<int> vector_1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "vector_1: " << vector_1 << endl;

    int index_ValueOver = find_if_ValueOver(vector_1, 15);
    cout << "\nFirst element in vector_1 larger than 15 is: " << vector_1[index_ValueOver] << "at index " << index_ValueOver << endl;
}
```
Output:
```console
vector_1: 3 3 12 14 17 25 30

First element in vector_1 larger than 15 is: 17 at index 4
```

### Check if interval of vector 1 is equal to vector 2
```c++
// Returns true if interval of table is equal to table2
bool approx_equal_interval(const vector<int> &table1, int nrOfElements, const vector<int> &table2)
{
    return equal(table1.begin(), table1.begin() + nrOfElements, table2.begin(), [](int number1, int number2) {
        return abs(number1 - number2) < 2;
    });
}

int main(){
    vector<int> vector_1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "vector_1: " << vector_1 << endl;
    vector<int> vector_2 = {2, 3, 12, 14, 24};
    cout << "vector_2: " << vector_2 << endl;

    bool equal = approx_equal_interval(vector_1, 5, vector_2);
    cout << "\nInterval [vector_1.begin(), vector_1.begin()+5> equal to vector_2? : " << boolalpha << equal << endl;
    equal = approx_equal_interval(vector_1, 4, vector_2);
    cout << "Interval [vector_1.begin(), vector_1.begin()+4> equal to vector_2? : " << boolalpha << equal << endl;
}
```
Output:
```console
vector_1: 3 3 12 14 17 25 30
vector_2: 2 3 12 14 24

Interval [vector_1.begin(), vector_1.begin()+5> equal to vector_2? : false
Interval [vector_1.begin(), vector_1.begin()+4> equal to vector_2? : true
```
### Replace odd numbers with 100
```c++
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

int main(){
    vector<int> vector_1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "vector_1: " << vector_1 << endl;

    vector<int> replaced = replace_oddNumbers(vector_1, 100);
    cout << "\nvector_1 after replacing odd numbers : " << replaced << endl;
}
```
Output:
```console
vector_1: 3 3 12 14 17 25 30

vector_1 after replacing odd numbers : 100 100 12 14 100 100 30
```
