#include <iostream>
#include <string>
using namespace std;

int main() {
    string s("Hello world \xF0\x9F\x98\x81");
    string s2 = s;
    string *sp = &s;
    s2.replace(7, 3, " sup");
    for (int i = 0; i < s.length(); i++) {
        // if (i < s.length() && i > s.length() / 2) {
        //     s[i] = 'x';
        // }
        cout << s.at(i) << sp->at(i) << s2.at(i) << endl;
    }
    cout << s << endl;
    cout << *sp << endl;
    cout << s2 << endl;
    return 0;
}

