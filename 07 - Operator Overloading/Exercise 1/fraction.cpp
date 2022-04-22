//
// Created by Sivert Utne on 07/10/2020.
//

#include "fraction.h"


Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int numerator, int denominator)
{
    set(numerator, denominator);
}

void Fraction::set(int numerator_, int denominator_)
{
    if(denominator_ != 0)
    {
        numerator = numerator_;
        denominator = denominator_;
        reduce();
    }
    else
    {
        throw "Zero as denominator";
    }
}

void Fraction::reduce()
{
    if(denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }
    int num = numerator;
    int den = denominator;
    int c;
    if(num < 0) num = -num;

    while(den > 0)
    {
        c = num % den;
        num = den;
        den = c;
    }
    numerator /= num;
    denominator /= num;
}

Fraction &Fraction::operator-=(const Fraction &other)
{
    set(numerator * other.denominator - denominator * other.numerator, denominator * other.denominator);
    return *this;
}

// -Fraction
Fraction Fraction::operator-() const {
    Fraction fraction;
    fraction.numerator = -numerator;
    fraction.denominator = denominator;
    return fraction;
}


// Fraction - Fraction
Fraction Fraction::operator-(const Fraction &other) const
{
    Fraction fraction = *this;
    fraction -= other;
    return fraction;
}

// Fraction - int
Fraction Fraction::operator-(const int &integer) const
{
    Fraction fraction;
    fraction.set(integer);
    fraction -= *this;
    return -fraction;
}

// int - Fraction
Fraction operator-(int integer, const Fraction &other)
{
    Fraction fraction;
    fraction = other - integer;
    return -fraction;
}



