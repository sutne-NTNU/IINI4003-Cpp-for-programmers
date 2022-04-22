#include <iostream>
#include <string>

using namespace std;

int main() {

    //a) Les inn tre ord fra brukeren. Kall variablene word1, word2 og word3.
    string word1, word2, word3;
    cout << "word1: ";
    cin >> word1;
    cout << "word2: ";
    cin >> word2;
    cout << "word3: ";
    cin >> word3;

    //b) Lag en streng der du skjøter sammen disse med mellomrom mellom og punktum til slutt. Kall variabelen sentence. Skriv ut.
    string sentence = word1 + " " + word2 + " " + word3 + ".";
    cout << sentence << endl;

    //c) Skriv ut lengden til hvert enkelt ord, og lengden til setningen som helhet.
    cout << "lengths:\n\tword1: " << word1.length() << "\n\tword2: " << word2.length() << "\n\tword3: "
         << word3.length() << "\n\tsentence: " << sentence.length() << endl;

    //d) Lag en kopi av sentence. Kall kopien sentence2.
    string sentence2 = sentence;

    //e) Bytt ut tegn nr 10-12 i sentence2 med x’er. Tegnene nummereres fra og med 0. Husk å kontrollere at dette er gyldige posisjoner! Skriv ut sentence og sentence2.
    cout << sentence2.length() << endl;
    if (sentence2.length() >= 12) {
        sentence2.replace(9, 3, "xxx");
    } else if (sentence2.length() >= 10) {
        for (int i = 9; i < (int) sentence2.length(); i++) {
            sentence2.replace(i, 1, "x");
        }
    }
    cout << "sentence: \t" << sentence << endl;
    cout << "sentence2: \t" << sentence2 << endl;

    //f) Lagre de fem første tegnene i sentence i objektet sentence_start. Skriv ut sentence og sentence_start. (Husk kontroll av gyldige posisjoner)
    string sentence_start;
    if (sentence.length() <= 5) {
        sentence_start = sentence;
    } else {
        sentence_start = sentence.substr(0, 5);
    }
    cout << "sentence_start: " << sentence_start << "\nsentence: " << sentence << endl;

    //g) Finn ut om sentence inneholder ordet "hallo". Skriv ut resultatet.
    cout << "sentence does ";
    if (sentence.find("hello") == string::npos) {
        cout << "NOT ";
    }
    cout << "contain \"hello\"." << endl;

    //h) Finn alle forekomster i sentence av strengen "er". Skriv ut resultatet.
    string find = "er";
    int counter = 0;
    size_t pos = sentence.find(find);
    while (pos != string::npos) {
        counter++;
        pos = sentence.find(find, pos + 1);
    }
    cout << "\"er\" occurs " << counter << " times in \"" << sentence << "\"" << endl;

    return 0;
}
