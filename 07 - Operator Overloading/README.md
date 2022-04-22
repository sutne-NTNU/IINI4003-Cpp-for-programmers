# Operator Overloading
## Exercise 1
In this exercise you will use the class Fraction from the lecture as inspiration.
- Create functions such that you can write `fraction1 – 5` og `5 – fraction1`. Create main.cpp to test your implementation.
- Theory: Explain how `5 - 3 - fraction1 - 7 - fraction2` is interpreted. What versions of the - operator are used?

### Result
```c++
Fraction fraction1(1, 2);
print("fraction1 = ", fraction1);
Fraction fraction2(3, 9);
print("fraction2 = ", fraction2);

print("\nfraction1 - 5 = ", fraction1 - 5);
print("5 - fraction1 = ", 5 - fraction1);
print("5 - 3 - fraction1 - 7 - fraction2 = ", 5 - 3 - fraction1 - 7 - fraction2);
```
Output:
```console
fraction1 = 1/2
fraction2 = 1/3

fraction1 - 5 = -9/2
5 - fraction1 = 9/2
5 - 3 - fraction1 - 7 - fraction2 = -35/6
```
`5 - 3 - fraction1 - 7 - fraction2` is only using left associative operators (only uses `-`) this means that this expression is interpreted from the left, and can be visualized like this: `((((5 - 3) - fraction1) - 7) - fraction2)` which means we are in this short expressions using the following implementations of the `-` operator (in order):
- Integer - Integer (5 - 3)
- Integer - Fraction (2 - 1/2)
- Fraction - Integer (3/2 - 7)
- Fraction - Fraction (-11/2 - 1/3) = -35/6



## Exercise 2
You are going to create a class with a set of integers (std::vector). It should contain different numbers. The numbers should not be sorted in any way. We are going to call this class `Set`.

You are going to implement member functions for the operations below. The member functions either have to be operators or constructors.

Implement the following operations:

- create a new empty Set
- find union of two sets. The function should create a new Set containing every value from the two sets, without duplicates. Example: Union of {1, 4, 3} and {4, 7} is {1, 4, 3, 7}.
- add a new number to the set. If the number already exists, don't do anything.
- be able to set one Set equal to another Set
- print a set

Create a short main program to test your implementation:

### Result
#### create a new empty Set + print a set (i created this in the main for simplicity)
```c++
Set set;
print("Empty set : ", set)
```
Output
```console
Empty set : [ ]
```



#### find union of two sets. The function should create a new Set containing every value from the two sets, without duplicates. Example: Union of {1, 4, 3} and {4, 7} is {1, 4, 3, 7}.

```c++
int init1[] = {1, 2, 3};
Set set1(3, init1);
print("Set1 : ", set1);

int init2[] = {3, 4, 5, 6};
Set set2(4, init2);
print("Set2 : ", set2);

print("\nset1 + set2 : ", set1 + set2);
```
Output
```console
Set1 : [ 1 2 3 ]
Set2 : [ 3 4 5 6 ]

set1 + set2 : [ 1 2 3 4 5 6 ]
```



#### add a new number to the set. If the number already exists, don't do anything.

```c++
print("Set1 += 4: ", set1 += 4);
print("Set1 += 3: ", set1 += 3);
```
Output
```console
Set1 : [ 1 2 3 ]
Set1 += 4: [ 1 2 3 4 ]
Set1 += 3: [ 1 2 3 4 ]
```



#### be able to set one Set equal to another Set

```c++
set1 = set2;
print("\nset1 = set2 -> set1 : ", set1);
```
Output
```console
Set1 : [ 1 2 3 ]
Set2 : [ 3 4 5 6 ]

set1 = set2 -> set1 : [ 3 4 5 6 ]
```
