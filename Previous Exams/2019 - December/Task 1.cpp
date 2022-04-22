//
// Created by Sivert Utne on 08/12/2020.
//
#include<iostream>


/**
 * By Values
 *
 * @param val1: value: a, or *ptr_a
 * @param val2: value: b, or *ptr_b
 */
void swap(int &val1, int &val2) {
    int tmp = val1;
    val1 = val2;
    val2 = tmp;
}


/**
 * By References
 *
 * @param ptr1: reference: &a
 * @param ptr2: reference: &b
 */
void swap(int *ptr1, int *ptr2) {
    int tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}


/**
 * Combination: Reference and Value
 *
 * @param ptr1: reference: &a
 * @param val2: value: a or *ptr_a
 */
void swap(int *ptr1, int &val2) {
    int tmp = *ptr1;
    *ptr1 = val2;
    val2 = tmp;
}


int main() {
    int a = 1, b = 2;
    swap(a, b);
    std::cout << a << ' ' << b << std::endl; // 2 1
    swap(&a, &b);
    std::cout << a << ' ' << b << std::endl; // 1 2
    int *c = &a;
    int *d = &b;
    swap(c, *d);
    std::cout << *c << ' ' << *d << std::endl; // 2 1
}