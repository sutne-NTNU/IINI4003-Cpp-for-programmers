
#include "fraction.cpp"
#include <iostream>
#include <string>


using namespace std;

void print(const string &text, const Fraction &fraction)
{
    cout << text << fraction.numerator << "/" << fraction.denominator << endl;
}

int main()
{
    Fraction fraction1(1,2);
    print("fraction1 = ", fraction1);
    Fraction fraction2(3,9);
    print("fraction2 = ", fraction2);

    print("\nfraction1 - 5 = ", fraction1 - 5);
    print("5 - fraction1 = ", 5 - fraction1);
    print("5 - 3 - fraction1 - 7 - fraction2 = ", 5 - 3 - fraction1 - 7 - fraction2);
}

