#include <iostream>
#include <string>
using namespace std;

// Arrays
// http://www.cplusplus.com/doc/tutorial/arrays/

// C-style
// int list[] {1, 2, 3}; // SHOULD ALSO WORK!
int list[] = {1, 2, 3};
int list2[4] = {1};

int main() {
    cout << list << endl;
    for (int i: list) {
        cout << i << endl;
    }
    cout << list2 << endl;
    for (int i: list2) {
        cout << i << endl;
    }
    /*
    OUTPUT
    0x107876070
    1
    2
    3
    0x107876080
    1
    0
    0
    0
    */
    return 0;
}

