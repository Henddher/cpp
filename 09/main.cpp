#include <iostream>
#include <string>
using namespace std;

// union and enum
// http://www.cplusplus.com/doc/tutorial/other_data_types/

enum class day {
    mon, tue, wed, thu, fri, sat, sun
};

int main() {
    day d = day::mon;
    return 0;
}

