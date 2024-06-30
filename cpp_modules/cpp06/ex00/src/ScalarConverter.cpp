/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:20:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/23 12:20:49 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

void handleInteger(int intValue);
void handleFloat(float floatVal);
int checkType(std::string s);
void handleInfs(std::string str);
void handleChar(char charVal);
void handleDouble(double doubleVal);
void printResult(values val);
bool isPseudo(std::string s);

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &cpy)
{
    *this = cpy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    (void)src;
    return *this;
}

void ScalarConverter::convert(std::string const &str)
{
    int type = checkType(str);
    double tmp = atof(str.c_str());

     if (tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min())
        type = DOUBLE;
    switch (type) {
        case CHAR:
            handleChar(str.at(0));
            break;
        case INT:
            handleInteger(atoi(str.c_str()));
            break;
        case FLOAT:
            handleFloat(atof(str.c_str()));
            break;
        case DOUBLE:
            handleDouble(atof(str.c_str()));
            break;
        case PSEUDO:
            handleInfs(str);
            break;
        case INVALID:
            std::cerr << "error: invalid string input" << std::endl;
            return;
    }
}

void printResult(values val) {
    std::cout << "char: ";
    
    if (val.validChar) {
        std::cout << (isprint(val.charVal) ? "'" + std::string(1, val.charVal) + "'\n" : "Non displayable\n");
        std::cout << "int: " << val.intVal << "\n";
    } else {
        std::cout << "impossible\nint: impossible\n";
    }
    std::cout << "float: " << val.floatVal << (std::fmod(val.floatVal, 1.0) == 0.0 ? ".0f" : "f") << "\n";
    std::cout << "double: " << val.doubleVal << (std::fmod(val.doubleVal, 1.0) == 0.0 ? ".0" : "") << "\n";
}

void handleInfs(std::string str)
{
    values val;

    val.floatVal = static_cast<float>(atof(str.c_str()));
    val.doubleVal = static_cast<double>(val.floatVal);
    val.intVal = INT_MIN;
    val.charVal = '\0';
    val.validChar = false;
    printResult(val);
}

void handleChar(char charVal)
{
    values val;

    val.charVal = charVal;
    val.floatVal = static_cast<float>(charVal);
    val.doubleVal = static_cast<double>(charVal);
    val.intVal = static_cast<int>(charVal);
    val.validChar = true;
    printResult(val);
}

void handleInteger(int intValue)
{
    values val;

    val.intVal = intValue;
    val.floatVal = static_cast<float>(intValue);
    val.doubleVal = static_cast<double>(intValue);
    val.charVal = static_cast<char>(intValue);
    val.validChar = true;
    printResult(val);
}

void handleDouble(double doubleVal)
{
    values val;

    val.doubleVal = doubleVal;
    val.floatVal = static_cast<float>(doubleVal);
    val.charVal = static_cast<char>(doubleVal);
    if (doubleVal > std::numeric_limits<int>::max()
            || doubleVal < std::numeric_limits<int>::min()) {
        val.intVal = INT_MIN;
        val.validChar = false;
    } else {
        val.intVal = static_cast<int>(doubleVal);
        val.validChar = true;
    }
    printResult(val);
}

void handleFloat(float floatVal)
{
    values val;

    val.floatVal = floatVal;
    val.doubleVal = static_cast<double>(floatVal);
    val.charVal = static_cast<char>(floatVal);
    if (floatVal > std::numeric_limits<int>::max()
            || floatVal < std::numeric_limits<int>::min()) {
        val.intVal = INT_MIN;
        val.validChar = false;
    } else {
        val.intVal = static_cast<int>(floatVal);
        val.validChar = true;
    }
    printResult(val);
}


bool isPseudo(std::string s) {
    return (
        s == "+inff" 
        || s == "+INFF" 
        || s == "-inff" 
        || s == "-INFF" 
        || s == "nan" 
        || s == "NAN" 
        || s == "-inf" 
        || s == "+inf" 
        || s == "nanf"
    );
}

int checkType(std::string s) {
    size_t i = 0;
    if (s.length() == 1 && !isdigit(s.at(0)) && !isspace(s.at(0)))
        return CHAR;
    if (isPseudo(s))
        return PSEUDO;
    while (i < s.length() && (s[i] == ' ' || s[i] == '\t'))
        i++;
    if (s[i] == '+' || s[i] == '-')
        i++;
    bool hasDigit = false;
    bool hasDot = false;

    while (i < s.length()) {
        if (isdigit(s[i])) {
            hasDigit = true;
        } else if (s[i] == '.') {
            if (hasDot)
                return (std::cerr << "Error:\n\tToo many dots found\n", INVALID);
            hasDot = true;
        } else if (s[i] == 'f') {
            return (i == s.length() - 1)
                ? FLOAT
                : (std::cerr << "Error:\n\t'f' is not at the end\n", INVALID);
        } else
            return INVALID;
        i++;
    }
    if (hasDot)
        return hasDigit ? DOUBLE : INVALID;
    return hasDigit ? INT : INVALID;
}