#include "RPN.hpp"

int main(int ac, char **av)
{	
	if (ac != 2) {
		std::cout << "Expected input: ./RPN <expression>\n";
		return 1;
	}

	RPN reversedPolishNotation;

	try {
		std::cout << reversedPolishNotation.calculate(av[1]) << "\n";
	}
	catch(const std::exception& e) {
		std::cerr << e.what();
	}
	return 0;
}