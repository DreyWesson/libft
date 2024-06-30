// #include <iostream>
// #include <vector>
// #include <deque>
// #include <algorithm>
// #include <iterator>
// #include <ctime>

// template <typename Iterator, typename Distance>
// Iterator next(Iterator iter, Distance n) {
//     std::advance(iter, n);
//     return iter;
// }

// template <typename Container>
// void merge(Container& container, int start, int mid, int end) {
//     int i, j, k;
//     int n1 = mid - start + 1;
//     int n2 = end - mid;

//     Container left(container.begin() + start, container.begin() + start + n1);
//     Container right(container.begin() + mid + 1, container.begin() + mid + 1 + n2);

//     i = 0;
//     j = 0;
//     k = start;

//     while (i < n1 && j < n2) {
//         if (left[i] <= right[j])
//             container[k++] = left[i++];
//         else
//             container[k++] = right[j++];
//     }

//     while (i < n1)
//         container[k++] = left[i++];

//     while (j < n2)
//         container[k++] = right[j++];
// }

// template <typename Container>
// void insertSort(Container& container, int start, int end) {
//     for (int i = start + 1; i <= end; ++i) {
//         typename Container::value_type key = container[i];
//         int j = i - 1;

//         for (; j >= start && container[j] > key; --j)
//             container[j + 1] = container[j];

//         container[j + 1] = key;
//     }
// }

// template <typename Container>
// void mergeInsertSort(Container& container, int start, int end) {
//     if (start < end) {
//         if (end - start < 10)
//             insertSort(container, start, end);
//         else {
//             int mid = start + (end - start) / 2;
//             mergeInsertSort(container, start, mid);
//             mergeInsertSort(container, mid + 1, end);

//             merge(container, start, mid, end);
//         }
//     }
// }

// int main(int argc, char* argv[]) {
//     if (argc < 2) {
//         std::cerr << "Error: Insufficient arguments\n";
//         return 1;
//     }

//     std::vector<int> original_sequence;
//     std::deque<int> original_sequence_copy;

//     try {
//         for (int i = 1; i < argc; ++i) {
//             int value = std::atoi(argv[i]);
//             if (value > 0) {
//                 original_sequence.push_back(value);
//                 original_sequence_copy.push_back(value);
//             } else {
//                 throw std::invalid_argument("Negative value encountered");
//             }
//         }
//     } catch (...) {
//         std::cerr << "Error: Invalid input\n";
//         return 1;
//     }

//     std::cout << "\033[31m""\033[1m""Before: ""\033[0m";
//     for (std::vector<int>::const_iterator it = original_sequence.begin(); it != original_sequence.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     clock_t start_data = clock();

//     mergeInsertSort(original_sequence, 0, original_sequence.size() - 1);

//     clock_t end_data = clock();
//     double duration_data = static_cast<double>(end_data - start_data) / CLOCKS_PER_SEC * 1000000;

//     std::cout << "\033[1m""\033[32m""After: ""\033[0m";
//     for (std::vector<int>::const_iterator it = original_sequence.begin(); it != original_sequence.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     clock_t start_sorting = clock();

//     original_sequence.clear();
//     original_sequence.reserve(original_sequence_copy.size());
//     for (std::deque<int>::const_iterator it = original_sequence_copy.begin(); it != original_sequence_copy.end(); ++it) {
//         original_sequence.push_back(*it);
//     }

//     mergeInsertSort(original_sequence, 0, original_sequence.size() - 1);

//     clock_t end_sorting = clock();
//     double duration_sorting = static_cast<double>(end_sorting - start_sorting) / CLOCKS_PER_SEC * 1000000;

//     std::cout << "Time to process a range of " << original_sequence.size() << " elements with std::vector: "
//               << duration_data << " us\n";
//     std::cout << "Time to process a range of " << original_sequence.size() << " elements with std::deque: "
//               << duration_sorting << " us\n";

//     return 0;
// }