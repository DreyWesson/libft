#include "revision.hpp"

using namespace std;

class Mark {
    int m;
    int n;
public:
    Mark() : m(0), n(0) {
        cout << "Constructor called!" << endl;
    }
    ~Mark() {
        cout << "Destructor called" << endl;
    }

    Mark(const Mark &cpy) {
            this->m = cpy.m;
            this->n = cpy.n;
    }

    Mark operator+(const Mark &cpy) {
        Mark tmp;

        tmp.m = this->m + cpy.m;
        tmp.n = this->n + cpy.n;
        return (tmp);
    }

    Mark operator-=(const Mark &cpy) {
        this->m -= cpy.m;
        this->n -= cpy.n;
        return (*this);
    }

    Mark operator++(const Mark &cpy) {

    }
    
    void display() const {
        cout << "m: " << m << ", n: " << n << endl;
    }

    void setValues(int m, int n) {
        this->m = m;
        this->n = n;
    }

};

int main() {
    Mark a;
    a.setValues(10, 20);
    
    Mark b;
    b.setValues(5, 15);
    
    // a -= b;
    Mark c = a + b;
    c.display();
    
    return 0;
}
