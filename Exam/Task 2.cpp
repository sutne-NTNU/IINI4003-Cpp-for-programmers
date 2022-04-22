#include<iostream>
#include<vector>

using namespace std;


class Vare {
public:
    string navn;
    int antall;

    Vare(string navn, int antall) : navn(move(navn)), antall(antall) {};

    virtual double mva() {
        return 0.25;
    }
};

class MatVare : public Vare {
public:
    MatVare(const string &navn, int antall) : Vare(navn, antall) {}

    double mva() override {
        return 0.15;
    }
};


class Butikk {
public:
    vector<Vare *> varer;

    Butikk() = default;
};

int main() {
    Butikk butikk;
    butikk.varer.emplace_back(new MatVare("NTNU-nistepakken", 5));
    butikk.varer.emplace_back(new Vare("NTNU-koppen", 10));
    for (auto &v : butikk.varer) {
        std::cout << v->navn << ", "
                  << v->antall << ", "
                  << v->mva() << std::endl;
    }
};