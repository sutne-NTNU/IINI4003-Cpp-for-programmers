//
// Created by Sivert Utne on 07/10/2020.
//

#include "Set.h"


Set::Set()
= default;

Set::Set(int nrOfItems, int *values)
{
    for(int i = 0; i < nrOfItems; i++){
        if(!exists(values[i])) set.push_back(values[i]);
    }
}

bool Set::exists(int integer)
{
    if(set.empty()) return false;
    for(auto i : set)
    {
        if(i == integer) return true;
    }
    return false;
}

Set Set::operator+(Set &other) const
{
    Set unionSet;
    // Add numbers from this set
    for(auto i : set) unionSet += i;
    // Add numbers from other set
    for(auto i : other.set)
    {
        if(!unionSet.exists(i)) unionSet += i;
    }
    return unionSet;
}

Set Set::operator+=(int integer)
{
    if(!exists(integer)) set.push_back(integer);
    return *this;
}

void Set::operator=(Set &other)
{
    set = other.set;
}






