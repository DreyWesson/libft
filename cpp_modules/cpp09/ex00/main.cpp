#include "./BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return ((std::cerr << "Usage: " << argv[0] << " <filename.csv>\n"), 1);
    
	BitcoinExchange btc("data.csv", argv[1]);
    return 0;
}