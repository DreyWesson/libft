#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
# include <iterator>
# include <stdexcept>
# include <iostream>
# include <list>
# include <deque>
# include <vector>

class NotFound : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Element not found in container.";
    }
};

template <typename T>
typename T::const_iterator easyfind(T const &container, int const element)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), element);
    return (it == container.end()) ? throw NotFound() : it;
}

#endif