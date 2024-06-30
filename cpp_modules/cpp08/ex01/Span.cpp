#include "./inc/Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() {}

Span::Span(const Span &cpy) : _N(cpy._N), _vec(cpy._vec) {}

Span &Span::operator=(const Span &obj)
{
    if (this != &obj)
    {
        this->_N = obj._N;
        this->_vec.clear();
        this->_vec.insert(this->_vec.begin(), obj._vec.begin(), obj._vec.end());
    }
    return (*this);
}

void Span::addNumber(int number)
{
    (_vec.size() >= _N) ? throw MaxSizeException() : _vec.push_back(number);
}

int Span::shortestSpan()
{
    if (_vec.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted(_vec);
    std::sort(sorted.begin(), sorted.end());
    std::vector<int> difference(_vec.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), difference.begin());
    int spanMin = *std::min_element(++(difference.begin()), difference.end());
    return spanMin;
}

int Span::longestSpan()
{
    if (_vec.size() < 2)
        throw NoSpanException();

    int min = *std::min_element(_vec.begin(), _vec.end());
    int max = *std::max_element(_vec.begin(), _vec.end());
    return max - min;
}

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
    for (Iterator it = begin; it != end; ++it)
        addNumber(*it);
}

void Span::fillConsecutiveNumbers()
{
    std::vector<int> consecutiveNumbers(_N);
    for (unsigned int i = 0; i < _N; i++)
        consecutiveNumbers[i] = i;
    addRange(consecutiveNumbers.begin(), consecutiveNumbers.end());
}

void Span::fillRandomNumbers()
{
    std::vector<int> randomNumbers(_N);
    srand(time(NULL));
    unsigned int i = 0;
    int element;

    while (i < _N)
    {
        element = rand() % (_N * 100);
        if (std::find(randomNumbers.begin(), randomNumbers.end(), element) == randomNumbers.end())
        {
            randomNumbers[i] = element;
            i++;
        }
    }
    addRange(randomNumbers.begin(), randomNumbers.end());
}

void Span::printElements()
{
    if (_vec.empty())
        std::cout << "Vector is empty\n";
    else
    {
        std::cout << "Vector elements:\n";
        for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
}

const char *Span::MaxSizeException::what() const throw()
{
    return ("max size reached!");
}

const char *Span::NoSpanException::what() const throw()
{
    return ("no span!");
}
