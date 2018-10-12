#include <iostream>
#include <string>

// Classes 1

using namespace std;

class Rect {
    // private: // the default
        int x, y, w, h;
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
};

// default constructor
Rect::Rect() {
}

Rect::Rect(int _x, int _y, int _w, int _h) {
    x = _x;
    y = _y;
    set_w(_w);
    set_h(_h);
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
    cout << "x:" << x << " y:" << y \
        << " w:" << w << " h:" << h \
        << " area:" << area() << endl;
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
    Rect r4(1, 2, 3, 4);
    r4.dump();

    // Uniform initialization
    // should call Rect::Rect(int, int, int, int) constructor
    // Rect r5 {2, 3, 4, 5}; // SHOULD WORK!

    return 0;
}

