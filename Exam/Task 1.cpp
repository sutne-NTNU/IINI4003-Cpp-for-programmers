#include<iostream>

using namespace std;


void replace_spaces(string &str, const char &replace_with) {
    for (char &c : str) {
        if (c == ' ') {
            c = replace_with;
        }
    }
}

string spaces_to_underscore1(const string &str) {
    replace_spaces((string &) str, '_');
    return str;
}

void spaces_to_underscore2(string &str) {
    replace_spaces(str, '_');
}


string spaces_to_underscore_or_character(const string &str, const char *character = nullptr) {
    if (character == nullptr) {
        return spaces_to_underscore1(str);
    } else {
        replace_spaces((string &) str, *character);
        return str;
    }
}

int main() {
    cout << spaces_to_underscore1("this is a string") << endl;

    string str("this is a string");
    spaces_to_underscore2(str);
    cout << str << endl;

    char chr('+');
    cout << spaces_to_underscore_or_character("this is a string", &chr) << endl;
    cout << spaces_to_underscore_or_character("this is a string", nullptr) << endl;
    cout << spaces_to_underscore_or_character("this is a string") << endl;
};