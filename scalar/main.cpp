#include <iostream>
#include <string>

// template specialization
// http://www.cplusplus.com/doc/tutorial/templates/

using namespace std;

enum class ScalarType {Boolean, String, Int};

template <class T>
class Scalar {
    T value;
    ScalarType type;
    public:
    Scalar(T _v);
    static Scalar<T> CreateScalar(ScalarType _type) {
        Scalar<T> s;
        s.type = _type;
        return s;
    };
    void set(T _v);
    void dump();
};

template <class T>
Scalar<T>::Scalar(T _v) {
    type = ScalarType::Int;
    value = _v;
}

// compiler error: static can only be specified inside class definition
// template <class T>
// static Scalar<T> Scalar<T>::CreateScalar(ScalarType _type) {
//     Scalar s;
//     s.type = _type;
// }

template <class T>
void Scalar<T>::dump() {
    string typ;
    switch (type) {
        case ScalarType::Boolean:
            typ = "ScalarType::Boolean";
            break;
        case ScalarType::String:
            typ = "ScalarType::String";
            break;
        case ScalarType::Int:
            typ = "ScalarType::Int";
            break;
        default:
            typ = "unknown";
            break;
    }
    cout << "type: " << typ << " value: " << value << endl;
}

template <class T>
void Scalar<T>::set(T _v) {
    value = _v;
}

// class template specialization
// template <>
// class Scalar <char> {
// };


int main() {
    Scalar<int> s(-1);
    s.dump();
    s.set(5);
    s.dump();
    return 0;
}

