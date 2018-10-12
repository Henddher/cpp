#include <iostream>
#include <string>
using namespace std;

string mult(const string& s);

int main() {
    string s ("Hello ");
    string i, i2;
    cout << "number1 number2:" << endl;
    cin >> i >> i2;
    cout << endl;
    s += i;
    cout << s << endl;
    s += i2;
    cout << s << endl;

    string rs ("RANDOM 😀");
    rs = mult(rs);
    cout << rs << endl;

    return 0;
}

string mult(const string& s) {
    string ls = s;
    string is;
    int m;
    cout << "string:" << endl;
    cin >> is;
    cout << "\nmultiplier:" << endl;
    cin >> m;
    cout << endl;
#if __has_extension(cxx_range_for)
    for (char c : ls) {
        for (int i = 0; i < m; i++) {
            ls += c + is;
        }
    }
#endif
    return ls;
}
