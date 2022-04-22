//
// Created by Sivert Utne on 09/10/2020.
//
#include <iostream>


using namespace std;


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


int main()
{
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    if(p1 > p2) cout << "p1 is largest" << endl;
    else cout << "p2 is largest" << endl;

    auto sum = p1 + p2;
    cout << "Sum: " << sum << endl;
}