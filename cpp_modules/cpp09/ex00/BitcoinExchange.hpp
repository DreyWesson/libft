#ifndef BTC_HPP
# define BTC_HPP

#include <iostream>
#include <string> 
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <sys/stat.h>
#include <cstring>

class BitcoinExchange {
public:
    BitcoinExchange(std::string const database, std::string const inputfile);
    BitcoinExchange(const BitcoinExchange& that);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& obj);

private:
    std::map<std::string, double> _container;
    std::fstream _database;
    std::fstream _inputFile;

    bool    openFile(std::string fileName, std::fstream & fs);
    bool    loadDatabase();
    void    parseInputfile();
    bool    checkDate(std::string date);
    bool    checkValue(std::string line);
    double  findRate(std::string date);

};

#endif