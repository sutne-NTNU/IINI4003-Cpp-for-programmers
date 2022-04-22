//
// Created by Sivert Utne on 09/10/2020.
//
#include <iostream>
#include <string>


template<typename Type>
bool equal(Type &a, Type &b)
{
    if(a == b) return true;
    else return false;
}

bool equal(double a, double b)
{
    double diff = abs(a - b);
    if(diff < 0.00001) return true;
    else return false;
}

void print(const std::string &info, bool equal)
{
    std::cout << info << (equal ? "True" : "False") << std::endl;
}

int main()
{
    print("equal(42, 42) : ", equal(42, 42));
    print("equal(24, 42) : ", equal(24, 42));

    print("\nequal('a', 'a') : ", equal('a', 'a'));
    print("equal('a', 'b') : ", equal('a', 'b'));

    print("\nequal(\"test\", \"test\") : ", equal("test", "test"));
    print(R"(equal("best", "test") : )", equal("best", "test"));

    print("\nequal(12.3, 12.3) : ", equal(12.3, 12.3));
    print("equal(12.3, 12.2) : ", equal(12.3, 12.2));
    print("equal(12.3, 12.300001) : ", equal(12.3, 12.300001));
    print("equal(12.3, 12.29999) : ", equal(12.3, 12.29999));
}

