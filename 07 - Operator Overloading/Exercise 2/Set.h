//
// Created by Sivert Utne on 07/10/2020.
//

#pragma once

#include <vector>


class Set
{
private:
    bool exists(int integer);
public:
    std::vector<int> set;

    Set(); // Create empty Set
    explicit Set(int nrOfItems, int values[]); // Initialize set with values

    Set operator+(Set &other) const; // Returns union of the sets (all unique items from both)
    Set operator+=(int integer); // Adds an int to the set
    void operator=(Set &other); // sets one Set equal to another set
};
