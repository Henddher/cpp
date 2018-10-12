#include <iostream>
#include <string>
using namespace std;

int main() {
    // http://www.cplusplus.com/doc/tutorial/constants/
    // In raw strings, backslashes and single and double quotes are all valid
    // characters; the content of the literal is delimited by an initial
    // R"sequence( and a final )sequence", where sequence is any sequence of
    // characters (including an empty sequence). The content of the string is
    // what lies inside the parenthesis, ignoring the delimiting sequence
    // itself.

    string s ("Hello world \xF0\x9F\x98\x81");
    cout << s << endl;
    // __has_feature MUST surround block to prevent compilation error
#if __has_feature(cxx_raw_string_literals)
    string s2 = R"(Hello world \xF0\x9F\x98\x81)";
    cout << s2 << endl;
#endif
    return 0;
}

