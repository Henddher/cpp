#include <iostream>
#include <string>

// Classes 1

using namespace std;

class Rect {
    // private: // the default
        int x, y, w, h;
        string name;
    public:
        // constructor
        Rect();
        Rect(int _x, int _y, int _w, int _h);
        // getters/setters
        int get_x() {
            return x;
        }
        void set_x(int);
        int get_y() {
            return y;
        }
        void set_y(int);
        int get_w() {
            return w;
        }
        void set_w(int);
        int get_h() {
            return h;
        }
        void set_h(int);
        // utils
        int area() {
            return w * h;
        }
        void dump();
        // overloaded operators
        Rect operator | (const Rect& right);
        Rect& operator &= (const Rect& right);
};

// default constructor
Rect::Rect() {
    name = "anonymous";
}

// Rect::Rect(int _x, int _y, int _w, int _h) {
//     x = _x;
//     y = _y;
//     set_w(_w);
//     set_h(_h);
// }
// sugar syntax: list of initializations for class members after colon
// member objects (e.g. name) are default constructed if they aren't
// initialized after the colon
Rect::Rect(int _x, int _y, int _w, int _h): x(_x), y(_y), w(_w), h(_h) {
}

void Rect::set_x(int _x) {
    x = _x;
}

void Rect::set_y(int _y) {
    y = _y;
}

void Rect::set_w(int _w) {
    w = _w;
}

void Rect::set_h(int _h) {
    h = _h;
}

void Rect::dump() {
    cout << "name:" << name \
        << " x:" << x << " y:" << y \
        << " w:" << w << " h:" << h \
        << " area:" << area() << endl;
}

Rect Rect::operator | (const Rect& rhs) {
    // Union of 2 rects
    Rect res;
    res.x = min(x, rhs.x);
    res.y = min(y, rhs.y);
    int x2 = max(x + w, rhs.x + rhs.w);
    int y2 = max(y + h, rhs.y + rhs.h);
    res.w = x2 - res.x;
    res.h = y2 - res.y;
    return res;
}

Rect& Rect::operator &= (const Rect& rhs) {
    // Intersection with another rect
    int x1 = max(x, rhs.x);
    int y1 = max(y, rhs.y);
    int x2 = min(x + w, rhs.x + rhs.w);
    int y2 = min(y + h, rhs.y + rhs.h);
    w = x2 - x1;
    h = y2 - y1;
    x = x1; y = y1;
    return *this;
}


int main() {
    Rect r; // compiler error if Rect::Rect() is not declared
            // linker error if Rect::Rect() is not defined
    // OK: default constructor called
    r.dump();
    Rect r2;
    // OK: default constructor called
    r2.set_x(1);
    r2.set_y(1);
    r2.set_w(3);
    r2.set_h(4);
    r2.dump();
    /*
    OUTPUT
    ------
    x:0 y:0 w:-512485784 h:32766 area:1212928816
    x:1 y:1 w:3 h:4 area:12
    */

    // Rect r3(); // compiler error - default constructor cannot be called explicitly
    // default constructor called explicitly gets confused with a regular
    // function call
    Rect r4(4, 3, 2, 1);
    r4.dump();
    /*
    OUTPUT
    ------
    x:4 y:3 w:2 h:1 area:2
    */

    // Uniform initialization
    // should call Rect::Rect(int, int, int, int) constructor
    // Rect r5 {2, 3, 4, 5}; // SHOULD WORK!

    // Pointer
    Rect * rp = &r;
    rp->set_x(-1);
    rp->set_y(-1);
    rp->set_w(-2);
    rp->set_h(-5);
    rp->dump();

    // | operator
    Rect ra(-1, -1, 1, 1);
    Rect rb(0, 0, 1, 1);
    r = ra | rb;
    r.dump();

    // &= operator
    r &= ra;
    r.dump();

    return 0;
}

