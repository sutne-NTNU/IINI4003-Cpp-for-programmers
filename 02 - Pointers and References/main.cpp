#include <iostream>


using namespace std;

// til Oppgave 6
int findSum(const int *table, int length);

int main() {
    cout << "Oppgave 1" << endl;
    cout << "a)" << endl;
    int i = 3;   // Inneholder verdien 3
    int j = 5;   // Inneholder verdien 5
    int *p = &i; // Inneholder minneaddressen til i
    int *q = &j; // Inneholder minneaddressen til j
    cout << "i = " << i << "\t&i= " << &i << endl;
    cout << "j = " << j << "\t&j= " << &j << endl;
    cout << "p = " << p << "\t&p= " << &p << endl;
    cout << "q = " << q << "\t&q= " << &q << endl;

    cout << "\nb)" << endl;
    // i=3    j=5    p=&i     q=&j
    *p = 7;                          // i=7    j=5    p=&i     q=&j
    *q += 4;                         // i=7    j=9    p=&i     q=&j
    *q = *p + 1;                     // i=7    j=8    p=&i     q=&j
    p = q;                           // i=7    j=8    p=&j     q=&j
    cout << *p << " " << *q << endl; // *p og *q peker begge til j og vi får: "8 8"
    cout << "i = " << i << "\t&i= " << &i << endl;
    cout << "j = " << j << "\t&j= " << &j << endl;
    cout << "p = " << p << "\t&p= " << &p << endl;
    cout << "q = " << q << "\t&q= " << &q << endl;

    // Oppgave 4
    int a = 5;
    int b; //int &b;  kan ikke refere til en minneaddresse til noe som ikke finnes
    int *c;
    c = &b;
    a = b + *c; //*a = *b + *c;  a er en int og kan derfor ikke brukes som en pointer, samme med b
    b = 2;      // &b = 2;       kan ikke endre minneadressen til hvor b er lagret

    cout << "\n\n\nOppgave 5" << endl;
    double number;
    double *numberPointer = &number;
    double &numberReferance = number;
    number = 1;
    cout << number << endl;
    *numberPointer = 2;
    cout << number << endl;
    numberReferance = 3;
    cout << number << endl;

    cout << "\n\n\nOppgave 6" << endl;
    int table[20];
    for (int i = 0; i < 20; i++) {
        table[i] = i + 1;
    }
    cout << "De 10 første tallene:\t" << findSum(table, 10) << endl;
    cout << "De 5 neste tallene:\t" << findSum(&table[10], 5) << endl;
    cout << "De 5 siste tallene:\t" << findSum(&table[15], 5) << endl;
}

int findSum(const int *table, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += table[i];
    }
    return sum;
}
