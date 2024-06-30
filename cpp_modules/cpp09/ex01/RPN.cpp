#include "./RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &that)
{
	this->_container = that._container;
}

RPN& RPN::operator=(const RPN &obj)
{
	_container = obj._container;
	return (*this);
}

bool RPN::operationToken(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

double RPN::calculate(std::string input)
{
	int operandCount = 0; 
    int operatorCount = 0;

	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == ' ')
			continue;
		else if (isdigit(input[i]))
		{
			operandCount++;
			for (size_t j = 0; j + i < input.length(); j++)
			{
				if (!isdigit(input[i + j]))
				{
					_container.push(input.substr(i, j));
					i += j;
					break;
				}
			}
		}
		else if (operationToken(input[i]))
		{
			operatorCount++;
			if (_container.size() < 2)
				throw ErrorException();
			_container.push(input.substr(i, 1));
			proceed();
		}
		else
			throw ErrorException();
	}

    if (operandCount != operatorCount + 1)
        throw ErrorException();

	if (_container.size() != 1)
		throw ErrorException();

	return std::atoi(_container.top().c_str());
}

void RPN::proceed() 
{
	std::string operToken = _container.top();
	_container.pop();
	int b = std::atoi(_container.top().c_str());
	_container.pop();
	int a = std::atoi(_container.top().c_str());
	_container.pop();
	std::stringstream stream;
	if (operToken == "+")
		stream << a + b;
	if (operToken == "-")
		stream << a - b;
	if (operToken == "/")
	{
		if (b == 0)
			throw ErrorException();
		stream << a / b;
	}
	if (operToken == "*")
		stream << a * b;
	std::string output = "";
	stream >> output;
	_container.push(output);
}

const char *RPN::ErrorException::what() const throw() 
{
    return("Error\n");
}