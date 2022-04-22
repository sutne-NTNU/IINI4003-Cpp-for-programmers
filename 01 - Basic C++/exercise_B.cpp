#include <cstdlib>
#include <fstream>
#include <iostream>


using namespace std;

void read_temperatures(double temperatures[], int &length);

// Har gjort en liten endring slik at tallfilen kan ha ulikt antall temperaturer (istedenfor en const length = 5);
// for å kjøre oppgave b: endre "add_executable(Oving1 oppgave_a.cpp)" til "add_executable(Oving1 oppgave_b.cpp)" i CMakeLists.txt

int main() {
    int length = 0;
    double temperatures[10];

    read_temperatures(temperatures, length);
    cout << "Det var skrevet " << length << " temperaturer" << endl;

    int under = 0, mellom = 0, over = 0;
    for (int i = 0; i < length; i++) {
        if (temperatures[i] < 10) {
            under++;
        } else if (temperatures[i] > 20) {
            over++;
        } else {
            mellom++;
        }
    }
    cout << "\nAntall under 10: " << under << endl;
    cout << "Antall mellom 10 og 20: " << mellom << endl;
    cout << "Antall over 20: " << over << endl;
}

void read_temperatures(double temperatures[], int &length) {
    const char filename[] = "../tallfil.dat";
    ifstream file;
    file.open(filename);
    if (!file) {
        cout << "Feil ved åpning av fil." << endl;
        exit(EXIT_FAILURE);
    }

    double temp;
    while (file >> temp) {
        temperatures[length] = temp;
        length++;
    }
    file.close();
}

/* tallfil.dat innheolder 9 temperaturer:
 * 2 under 10
 * 3 mellom 10 og 20
 * 4 over 20
 */