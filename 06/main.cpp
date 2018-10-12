#include <iostream>
#include <string>
using namespace std;

// http://www.cplusplus.com/doc/tutorial/functions2/
// TEMPLATES

template <class T>
T adder(const T& a, const T& b);

int main() {

    // Implicit T
    int ia = 4;
    int ib = 5;
    cout << adder(ia, ib) << endl;
    double da = 4.49;
    double db = 5.5;
    cout << adder(da, db) << endl;
    string sa ("4.49");
    string sb ("5.5");
    cout << adder(sa, sb) << endl;
    cout << adder(sa.at(0), sb.at(0)) << endl;

    // Explicit T
    // NOTICE we are passing another type
    cout << adder<double>(ia, ib) << endl;
    cout << adder<int>(da, db) << endl;
    cout << adder<string>(sa, sb) << endl;
    cout << adder<char>(sa.at(0), sb.at(0)) << endl;

    return 0;
}

template <class T>
T adder(const T& a, const T& b) {
    return b + a;
}
