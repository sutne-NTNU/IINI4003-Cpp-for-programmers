# Templates
## Exercise 1
- Create a function-template that compares two values and checks if they are equal, you can assume that the comparison operators are already implemented for the types.
- Create a seperate function to handle doubles. Assume doubles are equal if the difference between them is less than 0.00001.
- Create a small main that test both the template version and the double version. Make sure the functions return proper values.

### Result
```c++
template<typename Type>
bool equal(Type &first, Type &second)
{
    if(first == second) return true;
    else return false;
}

bool equal(double first, double second)
{
    double diff = abs(first - second);
    if(diff < 0.00001) return true;
    else return false;
}
```
Output:
```console
equal(42, 42) : True
equal(24, 42) : False

equal('a', 'a') : True
equal('a', 'b') : False

equal("test", "test") : True
equal("best", "test") : False

equal(12.3, 12.3) : True
equal(12.3, 12.2) : False
equal(12.3, 12.300001) : True
equal(12.3, 12.29999) : False
```

## Exercise 2
You are going to create a template-class for pairs. The two elements in the pair can be of diferent types. The class should have the following implementations:

- A constructor that takes both values as parameteres.
- An operator that adds two pairs together by adding the first and second values of the pairs together.
- An operator to check if one pair is larger than another, compare them using the sum of their elements.

Assume that all other operators you might need of + and > already exists. What assumptions do you make?

The template should be used in the following program:
```c++
int main() {
  Pair<double, int> p1(3.5, 14);
  Pair<double, int> p2(2.1, 7);
  cout << "p1: " << p1.first << ", " << p1.second << endl;
  cout << "p2: " << p2.first << ", " << p2.second << endl;

  if (p1 > p2)
    cout << "p1 er størst" << endl;
  else
    cout << "p2 er størst" << endl;

  auto sum = p1 + p2;
  cout << "Sum: " << sum.first << ", " << sum.second << endl;
}
```
```console
p1: 3.5, 14
p2: 2.1, 7
p1 er størst
Sum: 5.6, 21
```

### Result
```c++
template<typename Type1, typename Type2>
class Pair
{
public:
    Type1 first;
    Type2 second;

    Pair(Type1 first, Type2 second) : first(first), second(second) {}

    Pair operator+(const Pair &other)
    {
        Pair pair = *this;
        // Assuming that "TypeX/Y += TypeX/Y" is already implemented
        pair.first += other.first;
        pair.second += other.second;
        return pair;
    }

    bool operator>(const Pair &other)
    {
        // Assuming that "TypeX/Y + TypeX/Y" is already implemented
        return (first + second) > (other.first + other.second);
    }

    friend ostream &operator<<(ostream &os, const Pair &pair)
    {
        return os << pair.first << ", " << pair.second;
    }
};
```
Output:
```console
p1: 3.5, 14
p2: 2.1, 7
p1 is largest
Sum: 5.6, 21
```
