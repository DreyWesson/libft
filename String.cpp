#include "String.hpp"

String::String() : _str(NULL) {
    cout << "Constructor called!!!" << endl;
}
String::String(const std::string str) : _str(str) {
    cout << "Parameterized constructor called!!!" << endl;
}
String::~String() {
    cout << "Destructor called!!" << get_str() << endl;
}

String::String(const String &cpy) {
    *this = cpy;
}

String &String::operator=(const String &cpy) {
    this->_str = cpy._str;

    return *this;
}