#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque> 
#include <sstream>
#include <ctime>
#include <iomanip>

class PmergeMe {
public:
    PmergeMe(void);
    ~PmergeMe(void);
    PmergeMe(const PmergeMe &src);
    PmergeMe& operator=(const PmergeMe &src);

    void parseInput(int ac, char **av);
    void printContainer(const std::string& message);
    void sortVector();
    void sortDeque();
    int getVecSize();
    int getQueueSize();

    class ErrorException: public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    template <typename Container>
    static void sort(Container& container);

private:
    std::vector<int> _vec;
    std::deque<int> _deq;

    template <typename Container>
    static void merge(Container& container, int start, int mid, int end);

    template <typename Container>
    static void insertSort(Container& container, int start, int end);

    template <typename Container>
    static void mergeInsertSort(Container& container, int start, int end);
};


template <typename Container>
void PmergeMe::sort(Container& container) {
    mergeInsertSort(container, 0, container.size() - 1);
}

template <typename Container>
void PmergeMe::merge(Container& container, int start, int mid, int end) {
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    Container left(container.begin() + start, container.begin() + start + n1);
    Container right(container.begin() + mid + 1, container.begin() + mid + 1 + n2);

    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2) 
        container[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i < n1)
        container[k++] = left[i++];
    while (j < n2)
        container[k++] = right[j++];
}

template <typename Container>
void PmergeMe::insertSort(Container& container, int start, int end) {
    for (int i = start + 1; i <= end; ++i) {
        typename Container::value_type key = container[i];
        int j = i - 1;
        for (; j >= start && container[j] > key; --j)
            container[j + 1] = container[j];
        container[j + 1] = key;
    }
}

template <typename Container>
void PmergeMe::mergeInsertSort(Container& container, int start, int end) {
    if (start < end) {
        if (end - start < 10)
            insertSort(container, start, end);
        else {
            int mid = start + (end - start) / 2;
            mergeInsertSort(container, start, mid);
            mergeInsertSort(container, mid + 1, end);
            merge(container, start, mid, end);
        }
    }
}

#endif