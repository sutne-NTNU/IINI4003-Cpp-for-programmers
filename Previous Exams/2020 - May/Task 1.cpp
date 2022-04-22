//
// Created by Sivert Utne on 08/12/2020.
//
#include<iostream>


using namespace std;


size_t replace(string &str, size_t pos, const string &replace_with) {
    str.erase(pos, 1); // erase original symbol
    str.insert(pos, replace_with); // insert new symbols in its place
    return pos + replace_with.size(); // return last index of characters we inserted
}


/**
 * Escape in-place in original string
 */
void escape(string &str) {
    for (size_t pos = 0; pos < str.size();) {
        if (str[pos] == '<')
            pos = replace(str, pos, "&lt;");
        else if (str[pos] == '>')
            pos = replace(str, pos, "&gt;");
        else if (str[pos] == '&')
            pos = replace(str, pos, "&amp;");
        else
            pos++;
    }
}

/**
 * Escape in-place in copy of original, then return the escaped copy
 */
string escape(const string &str) {
    escape((string &) str);
    return str;
}


int main() {
    cout << escape("Escape these symbols: <<&>>") << endl;
    std::string text("Escape these symbols as well: >>&<<");
    escape(text);
    cout << text << endl;
}

