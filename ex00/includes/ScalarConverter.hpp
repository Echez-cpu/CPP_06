#ifndef  SCALARCONVERTER_HPP
#define  SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
#include <limits.h>
#include <float.h>
#include <cstdlib>
#include <cerrno>

typedef std::string str;


class ScalarConverter {

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &source);
		~ScalarConverter();


ScalarConverter 	&operator=(ScalarConverter const &original_copy);

public:
		static void	convert(const str &lit);

};

#endif
