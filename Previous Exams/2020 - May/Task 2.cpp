//
// Created by Sivert Utne on 08/12/2020.
//
#include <utility>
#include<vector>
#include<iostream>


using namespace std;


class Animal {
public:
    string name;

    virtual ~Animal() = default; // can't create a object that is just an "Animal"

    explicit Animal(string name) : name(move(name)) {}

    virtual string species() const = 0;

    friend ostream &operator<<(ostream &ostream, const Animal &animal) {
        return ostream << animal.species() << " named " << animal.name;
    }
};


class Cat : public Animal {
public:
    explicit Cat(const string &name) : Animal(name) {}

    string species() const override { return "Cat"; }
};


class Dog : public Animal {
public:
    explicit Dog(const string &name) : Animal(name) {}

    string species() const override { return "Dog"; }
};


int main() {
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(new Cat("Oreo"));
    animals.emplace_back(new Dog("Buddy"));
    animals.emplace_back(new Dog("Charlie"));
    // animals.emplace_back(new Animal());      // Should cause compilation error
    // animals.emplace_back(new Animal("Max")); // Should cause compilation error
    for (auto &animal : animals) {
        cout << *animal << endl;
    }
}