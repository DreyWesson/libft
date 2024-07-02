#ifndef STRING_HPP
# define STRING_HPP

#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
        std::string _str;

protected:

public:
    String(void);
    String(const std::string str);
    ~String(void);

    String(const String &cpy);
    String& operator=(const String &cpy);


    void set_str(std::string s);
    const std::string get_str() const;
    size_t strlen_() const;
    char charAt(size_t index) const;
};

#endif