#ifndef REVISION_HPP
# define REVISION_HPP

# include <iostream>
# include <cstring>

using namespace std;

class String_ {

private:
    std::string value;

public:
    String_( void );
    ~String_( void );
    String_(const String_ &cpy);
    String_ &operator=(const String_ &cpy);

    void sayHello(void);

    char *_strstr(const char *haystack, const char *needle);
};

#endif