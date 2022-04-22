//
// Created by Sivert Utne on 08/12/2020.
//
#include<iostream>


using namespace std;


class NorwegianKrone {
public:
    static double toEuro(double amount) { return amount * 0.1; }
};


class Euro {
public:
    static double toEuro(double amount) { return amount * 1; }
};


template<class CurrencyType>
class Currency {
public:
    double amount{};

    explicit Currency(double amount) : amount(CurrencyType::toEuro(amount)) {}

    friend ostream &operator<<(ostream &ostream, const Currency<CurrencyType> &currency) {
        return ostream << "€" << currency.amount;
    }

    template<class CurrencyType_other>
    Currency operator+(const Currency<CurrencyType_other> &other) {
        this->amount += other.amount;
        return *this;
    }
};


int main() {
    cout << Currency<NorwegianKrone>(1) << endl;
    cout << Currency<Euro>(1) << endl;
    cout << (Currency<NorwegianKrone>(10) +
             Currency<Euro>(10) +
             Currency<NorwegianKrone>(10)) << endl;
}