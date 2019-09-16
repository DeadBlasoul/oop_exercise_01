// stdlib headers:
#include <cstdio>
#include <iostream>
#include <string>

// LabLib headers:
#include <complex.hpp>

using namespace std;

void ToUpper(string& str);

int main() {
    string input;
    while (cin) {
        cin >> input;
        ToUpper(input);
        Complex left, right;
        left.Read(cin);
        right.Read(cin);

        if (cin.fail()) {
            break;
        }

        if (input == "ADD") {
            left.Add(right).Write(cout);
        }
        else if (input == "SUB") {
            left.Sub(right).Write(cout);
        }
        else if (input == "MUL") {
            left.Mul(right).Write(cout);
        }
        else if (input == "DIV") {
            left.Div(right).Write(cout);
        }
        else if (input == "EQU") {
            cout << (left.Equ(right) ? "True" : "False");
        }
        else if (input == "CMP") {
            cout << Compare(left, right);
        }
        cout << endl;
        cout.flush();
    };
}

void ToUpper(string& str) {
    for (auto& c : str) {
        c = static_cast<remove_reference_t<decltype(c)>>(toupper(c));
    }
}
