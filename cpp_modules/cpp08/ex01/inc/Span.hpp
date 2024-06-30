#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
#include <set>

class Span
{
private:
    unsigned int _N;
    std::vector<int> _vec;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &that);
    Span &operator=(const Span &obj);
    ~Span();


    void addNumber(int number);
    int shortestSpan();
    int longestSpan();

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end);

    void fillConsecutiveNumbers();
    void fillRandomNumbers();
    void printElements();

    class MaxSizeException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class NoSpanException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif
