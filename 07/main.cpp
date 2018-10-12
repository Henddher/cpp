#include <iostream>
#include <string>
#include "exify.hpp"

using namespace std;

int main() {
    string s ("Hello world \xF0\x9F\x98\x81");
    cout << exify(s) << endl;
    return 0;
}

