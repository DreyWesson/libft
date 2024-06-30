#include "../inc/PMergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) : _vec(src._vec), _deq(src._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe &src)
{
	_vec = src._vec;
	_deq = src._deq;
	return (*this);
}

void PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
    {
		std::stringstream ss(argv[i]);
		int nb = 0;
		
		if (!(ss >> nb) || !ss.eof()) 
			throw ErrorException();
		if (nb < 0)
			throw ErrorException();
		_vec.push_back(nb);
		_deq.push_back(nb);
	}
}

void PmergeMe::printContainer(const std::string& message) {
    std::cout << message;
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << " ";
        if (_vec[i] != _deq[i])
            throw ErrorException();
    }
    std::cout << "\n";
}

void PmergeMe::sortVector()
{
    mergeInsertSort(_vec, 0, _vec.size() - 1);
}

void PmergeMe::sortDeque() 
{
    mergeInsertSort(_deq, 0, _deq.size() - 1);
}

int PmergeMe::getVecSize() {
    return (_vec.size());
}

int PmergeMe::getQueueSize() {
    return (_deq.size());
}

const char *PmergeMe::ErrorException::what() const throw()
{
    return("Error\n");
}