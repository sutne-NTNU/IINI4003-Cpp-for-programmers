//
// Created by Sivert Utne on 07/10/2020.
//
#include <iostream>
#include "Set.cpp"


using namespace std;

void print(const std::string &tag, const Set &set)
{
    std::cout << tag << "[ ";
    for(auto i : set.set) std::cout << i << " ";
    std::cout << "]" << std::endl;
}

int main()
{
    Set set;
    print("Empty set : ", set);

    int init1[] = {1, 2, 3};
    Set set1(3, init1);
    print("Set1 : ", set1);

    int init2[] = {3, 4, 5, 6};
    Set set2(4, init2);
    print("Set2 : ", set2);

    print("\nset1 + set2 : ", set1 + set2);

    print("\nSet1 += 4: ", set1 += 4);
    print("Set1 += 3: ", set1 += 3);

    set1 = set2;
    print("\nset1 = set2 -> set1 : ", set1);
    return 0;
}

