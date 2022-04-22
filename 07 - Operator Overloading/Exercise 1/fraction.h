//
// Created by Sivert Utne on 07/10/2020.
//

#pragma once


class Fraction
{
public:
    int numerator{};
    int denominator{};

    Fraction();
    Fraction(int numerator, int denominator);
    void set(int numerator_, int denominator_ = 1);
    Fraction &operator-=(const Fraction &other);
    Fraction operator-() const;
    Fraction operator-(const Fraction &other) const;
    Fraction operator-(const int &integer) const;

private:
    void reduce();
};