#include <iostream>


using namespace std;

int main() {
    const int length = 5;

    cout << "Du skal skrive inn " << length << " temperaturer.\n";
    double temp;

    int under = 0, mellom = 0, over = 0;
    for (int i = 1; i <= length; i++) {
        cout << "Temperatur " << i << ": ";
        cin >> temp;
        if (temp < 10) {
            under++;
        } else if (temp > 20) {
            over++;
        } else {
            mellom++;
        }
    }
    cout << "\nAntall under 10: " << under << endl;
    cout << "Antall mellom 10 og 20: " << mellom << endl;
    cout << "Antall over 20: " << over << endl;
}
