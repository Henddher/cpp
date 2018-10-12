#include <string>
#include "exify.hpp"

namespace std {
    string exify(const string& s) {
        string ls;
        for (char c: s) {
            ls += " X";
            ls += c;
            ls += "X ";
        }
        return ls;
    }
}
