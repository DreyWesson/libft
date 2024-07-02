#include "String.hpp"

String::String() : _str("") {
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
void String::set_str(string s) {
    _str = s;
}

const std::string String::get_str() const {
    return _str;
}

size_t String::strlen_() const {
    size_t counter = 0;

    std::string s = get_str();

    while (s[counter] != '\0')
        counter++;

    return counter;
}

char String::charAt(size_t index) const {
    if (index >= this->strlen_()) {
        return '\0';
    }
    return _str[index];
}
