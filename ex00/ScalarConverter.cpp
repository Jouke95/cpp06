#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

bool ScalarConverter::isChar(const std::string& input) {
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string& input) {
	size_t start = 0;

	if (input[0] == '-' || input[0] == '+')
		start = 1;
	if (start >= input.length())
		return false;
	for (size_t i = start; i < input.length(); i++) {
		if (!isdigit(input[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& input) {
	if (input[input.length() - 1] != 'f')
		return false;
	std::string withoutF = input.substr(0, input.length() - 1);

	size_t start = 0;
	size_t dotCount = 0;

	if (withoutF[0] == '-' || withoutF[0] == '+')
		start = 1;
	if (start >= withoutF.length())
		return false;
	for (size_t i = start; i < withoutF.length(); i++) {
		if (!isdigit(withoutF[i]) && withoutF[i] != '.')
			return false;
		if (withoutF[i] == '.')
			dotCount++;
	}
	if (dotCount != 1)
			return false;
	return true;
}

bool ScalarConverter::isDouble(const std::string& input) {
	size_t start = 0;
	size_t dotCount = 0;

	if (input[0] == '-' || input[0] == '+')
		start = 1;
	if (start >= input.length())
		return false;
	for (size_t i = start; i < input.length(); i++) {
		if (!isdigit(input[i]) && input[i] != '.')
			return false;
		if (input[i] == '.')
			dotCount++;
	}
	if (dotCount != 1)
			return false;
	return true;
}

bool ScalarConverter::isSpecial(const std::string& input) {
	std::string specials[] = {"nan", "nanf", "-inf", "-inff", "+inf", "+inff"};
	size_t size = sizeof(specials) / sizeof(specials[0]);

	for (size_t i = 0; i < size; i++) {
		if (input == specials[i])
			return true;
	}
	return false;
}

void ScalarConverter::printChar(int value) {
	if ((value >= 0 && value <= 31) || value == 127)
		std::cout << "char: non displayable" << std::endl;
	else if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

void ScalarConverter::convertInt(const std::string& input) {
	std::stringstream ss(input);
	int value;
	ss >> value;
		printChar(value);
		std::cout << "int: " << value << std::endl;
		std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::convertFloat(const std::string& input) {
	std::stringstream ss(input.substr(0, input.length() - 1));
	float value;
	ss >> value;
	printChar(static_cast<int>(value));
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertDouble(const std::string& input) {
	std::stringstream ss(input);
	double value;
	ss >> value;
	printChar(static_cast<int>(value));
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convertChar(const std::string& input) {
	char c = input[1];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertSpecial(const std::string& input) {
	std::cout << "char: impossible\nint: impossible" << std::endl;
	if (input == "nan" || input == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (input == "-inf" || input == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (input == "+inf" || input == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& input) {
	if (input.empty()) {
		std::cout << "Error: empty string" << std::endl;
		return;
	}
	if (isSpecial(input))
		convertSpecial(input);
	else if (isChar(input))
		convertChar(input);
	else if (isInt(input))
		convertInt(input);
	else if (isFloat(input))
		convertFloat(input);
	else if (isDouble(input))
		convertDouble(input);
	else {
		std::cout << "Wrong input!!" << std::endl;
	}
}
