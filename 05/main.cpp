#include <iostream>
#include <string>
using namespace std;

// http://www.cplusplus.com/doc/tutorial/functions2/
// Note that a function cannot be overloaded only by its return type. At least
// one of its parameters must have a different type.

int adder(int i, int j);
double adder(double i, double j);
string adder_by_val_copies(string i, string j);
string adder_by_ref(string& i, string& j);
string adder_by_const_ref(const string& i, const string& j);

int main() {
    cout << adder(4, 5) << endl;
    cout << adder(4.49, 5.5) << endl;
    string a, b;
    a = "4";
    b = "5";
    cout << adder_by_val_copies(a, b) << endl;
    cout << a << " " << b << endl;
    a = "4";
    b = "5";
    cout << adder_by_ref(a, b) << endl;
    cout << a << " " << b << endl;
    a = "4";
    b = "5";
    cout << adder_by_const_ref(a, b) << endl;
    cout << a << " " << b << endl;

    /*
    OUTPUT
    ------
    9
    9.99
    4!5?5?
    4 5
    4!5?5?
    4!5? 5?
    45
    4 5
    */

    return 0;
}


int adder(int i, int j) {
    return i + j;
}

double adder(double i, double j) {
    return i + j;
}

string adder_by_val_copies(string i, string j) {
    i += "!";
    j += "?";
    i += j;
    return i + j;
}

string adder_by_ref(string& i, string& j) {
    i += "!";
    j += "?";
    i += j;
    return i + j;
}

string adder_by_const_ref(const string& i, const string& j) {
    // // Compiler error
    // i += "!";
    // j += "?";
    // i += j;
    return i + j;
}
