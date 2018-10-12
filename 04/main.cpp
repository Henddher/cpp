#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "option:" << endl;
    string io;
    cin >> io;
    switch (io.length()) {
        case 2:
            s = "XX" + io;
            break;
        case 4:
            s = "xxxx" + io;
            break;
        case 0:
        default:
            s = "Hello world \xF0\x9F\x98\x81";
            break;
    }
    cout << s << endl;
    return 0;
}

