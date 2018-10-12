#include <iostream>
#include <string>
using namespace std;

int main() {
    string s ("Hello world \xF0\x9F\x98\x81");
    cout << s << endl;
    return 0;
}

