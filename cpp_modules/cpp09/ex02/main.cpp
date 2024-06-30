#include "./inc/PMergeMe.hpp"

void printDuration(double duration, int size) {
    std::cout << "Time to process a range of " << size << " elements with std::vector : "
        << std::fixed << std::setprecision(6) << duration * 1e3 << " us\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Insufficient arguments\n";
        return 1;
    }

    PmergeMe sorter;
    try {
        sorter.parseInput(argc, argv);
		sorter.printContainer("\033[31m""\033[1m""Before: ""\033[0m"); 
		
		std::clock_t start_vec = std::clock();
		sorter.sortVector();
		std::clock_t end_vec = std::clock();

		std::clock_t start_deq = std::clock();
		sorter.sortDeque();
		std::clock_t end_deq = std::clock();
		
		sorter.printContainer("\033[1m""\033[32m""After: ""\033[0m");
        double  vecTime = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

        printDuration(vecTime, sorter.getVecSize());
        double  deqTime = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC;
        printDuration(deqTime, sorter.getQueueSize());

    } catch (...) {
        std::cerr << "Error: Invalid input\n";
        return 1;
    }
    return 0;
}
