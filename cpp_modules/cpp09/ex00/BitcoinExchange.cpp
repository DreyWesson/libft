#include "./BitcoinExchange.hpp"



BitcoinExchange::BitcoinExchange(std::string const database, std::string const inputFile)
{
    if (!openFile(database, _database) || !openFile(inputFile, _inputFile) || !loadDatabase())
        return ;
    parseInputfile();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &that)
{
	this->_container = that._container;
}

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj) 
{
	this->_container = obj._container;
	return *this;
}

bool    BitcoinExchange::openFile(std::string fileName, std::fstream & fs)
{
	struct stat filecheck;
      
    if ( stat( fileName.c_str(), &filecheck ) != 0 ) {
        std::cerr << "Error: " <<  fileName + ": invalid file\n";
        return (false);
    }
    if ( ( filecheck.st_mode & S_IFREG ) == 0 ) {
        std::cerr << "Error: " <<  fileName + ": is a directory\n";
        return (false);
    }
    if ( ( filecheck.st_mode & S_IXUSR ) != 0 ) {
        std::cerr << "Error: " <<  fileName + ": is an excutable\n";
        return (false);
    }
    fs.open(fileName);
    if (!fs.is_open())
    {
        if (!fileName.compare(fileName.length() - 4, 4, ".csv"))
            std::cerr << "Error: could not open database\n";
        else
            std::cerr << "Error: " <<  fileName + " : could not open input file\n";
        return (false);
    }
    return true;
}

bool    BitcoinExchange::loadDatabase()
{
    std::string buffer, date;
    double value;

    getline(_database, buffer);
    if (buffer != "date,exchange_rate")
        return (std::cerr << "Error: wrong database header\n", false);
    while (getline(_database, buffer))
    {
        if (buffer.length() < 12 || buffer[10] != ',')
            return (std::cout << "Error: bad input in database \n", false);
        if (!checkDate(buffer))
            return (std::cout << "in database\n", false);
        value = atof(buffer.substr(11).c_str());
        if ((!value && (std::string)buffer.substr(11).c_str() != "0") || value < 0)
            return (std::cerr << "Error: bad input in database\n", false);

        date = buffer.substr(0, 10);
        _container[date] = value;
    }
    return true;
}

bool    BitcoinExchange::checkDate(std::string date)
{
    int year, month, day;

    year = std::atoi(date.substr(0, 4).c_str());
    month = std::atoi(date.substr(5, 2).c_str());
    day = std::atoi(date.substr(8, 2).c_str());

    if (date[4] != '-' || date[7] != '-' || year < 1 \
        || month < 1 || month > 12 || day < 1 || day > 31)
            return (std::cout << "Error: bad input ", false);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (std::cout << "Error: bad input ", false);
    bool isLeapyear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (month == 2 && ((isLeapyear && day > 29) || (!isLeapyear && day > 28)))
        return (std::cout << "Error: bad input ", false);
    return true;
}

bool    BitcoinExchange::checkValue(std::string line)
{
    double value = std::atof(line.c_str());

    if ((!value && line.substr(0, 1) != "0") || value < 0)
		return (std::cout << "Error: not a positive integer.", false);
    if (value > 1000)
		return (std::cout << "Error: too large a number.", false);
    return true;
}

double  BitcoinExchange::findRate(std::string date)
{
    std::map<std::string, double>::iterator it = _container.lower_bound(date);
    if (it != _container.end())
    {
        if (it->first != date)
            --it;
        return it->second;
    }
    else if (!_container.empty())
        return (--it)->second;
    return -1;
}

void    BitcoinExchange::parseInputfile()
{
    std::string buffer, date, value;
    double rate;

    getline(_inputFile, buffer);
    if (buffer != "date | value")
    {
        std::cout << "Error: invalid input file\n";
        return ;
    }
    while(getline(_inputFile, buffer))
    {
        if (buffer.length() < 13 || buffer[10] != ' ' || buffer[11] != '|' || buffer[12] != ' ')
        {
            std::cout << "Error: bad input => " << buffer << std::endl;
            continue ;
        }
        date = buffer.substr(0, 10);
        value = buffer.substr(13);
        if (!checkDate(buffer))
            std::cout << "=> " << buffer << std::endl;
        else if (!checkValue(value))
            std::cout << std::endl;
        else if ((rate = findRate(date)) == -1)
            std::cout << "Error: no exchange rate available\n";
        else
            std::cout << date << " => " << value << " = "
                << atof(value.c_str()) * rate << std::endl;
    }
}
