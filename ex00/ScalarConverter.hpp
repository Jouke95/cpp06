#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);

		static bool isChar(const std::string& input);
		static bool isInt(const std::string& input);
		static bool isFloat(const std::string& input);
		static bool isDouble(const std::string& input);
		static bool isSpecial(const std::string& input);

		static void printChar(int value);

		static void convertInt(const std::string& input);
		static void convertFloat(const std::string& input);
		static void convertDouble(const std::string& input);
		static void convertChar(const std::string& input);
		static void convertSpecial(const std::string& input);

	public:
		static void convert(const std::string& input);
};

#endif