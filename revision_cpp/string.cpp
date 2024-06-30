#include "revision.hpp"

String_::String_(void) :value("Hello") {
    return;
}

String_::~String_(void) {
    cout << "Destructor called! " << endl;
    return;
}

void String_::sayHello() {
    cout << value << endl;
}