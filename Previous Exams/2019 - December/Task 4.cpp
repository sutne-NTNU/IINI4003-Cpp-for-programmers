//
// Created by Sivert Utne on 08/12/2020.
//
#include<iostream>
#include<vector>


using namespace std;


class Car {
public:
    virtual ~Car() = default; // can't create a object that is just a "Car"



    virtual string brand() const = 0;

    virtual string engine() const = 0;


    friend ostream &operator<<(ostream &ostream, const Car &car) {
        return ostream << car.brand() << " with " << car.engine() << " engine";
    }
};


/*
 *
 * Types of motors
 *
 */

class Electric {
public:
    static string str() { return "electric"; }
};


class Gasoline {
public:
    static string str() { return "gasoline"; }
};


/*
 *
 * Brands
 *
 */

template<class MotorType> // to create: Saab<MotorType>
class Saab : public Car {
public:
    string brand() const override {
        return "Saab";
    }


    string engine() const override {
        return MotorType::str();
    }
};


template<class MotorType>
class Volvo : public Car {
public:
    string brand() const override {
        return "Volvo";
    }


    string engine() const override {
        return MotorType::str();
    }
};


int main() {
    vector<unique_ptr<Car>> cars;
    cars.emplace_back(new Saab<Electric>());
    cars.emplace_back(new Saab<Gasoline>());
    cars.emplace_back(new Volvo<Electric>());
    for (auto &car : cars) cout << *car << endl;
}