//
// Created by Sivert Utne on 08/12/2020.
//
#include<iostream>


using namespace std;


class Hot {
public:
    friend ostream &operator<<(ostream &ostream, const Hot &) {
        ostream << "hot";
        return ostream;
    }
};


class Cold {
public:
    friend ostream &operator<<(ostream &ostream, const Cold &) {
        ostream << "cold";
        return ostream;
    }
};


class Degrees {
public:
    auto operator+() { return Hot(); }


    auto operator-() { return Cold(); }
};


int main() {
    Degrees degrees;
    cout << +degrees << endl;
    cout << -degrees << endl;
}