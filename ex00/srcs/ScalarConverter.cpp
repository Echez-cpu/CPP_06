#include "../includes/ScalarConverter.hpp"

static void		charConvertion(str input) {
	std::cout << "char: " << input[0] << std::endl;
	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
}


static void		intConvertion(str input) {
	int	num = atoi(input.c_str());

	if (num < 0 || num > 127)
		std::cout << "char: impossible" << std::endl;
	else if (num < 32 || num == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(num) << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}


static void floatConvertion(str input) {
  
    float num = atof(input.c_str()); // std::stringstream can also be used. It is better actually, can detect errors safely
  
    int intNum = static_cast<int>(num);

    if (intNum < 0 || intNum > 127) {
        std::cout << "char: impossible" << std::endl;
    }
    else if (intNum < 32 || intNum == 127) {
        std::cout << "char: non-displayable" << std::endl;
    }
    else {
        std::cout << "char: " << static_cast<char>(intNum) << std::endl;
    }
    
    std::cout << "int: " << intNum << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(2) << num << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(num) << std::endl;
}


static void doubleConvertion(str input) {
  
    double num = atof(input.c_str()); // std::stringstream can also be used. It is better actually, can detect errors safely
  
    int intNum = static_cast<int>(num);

    if (intNum < 0 || intNum > 127) {
        std::cout << "char: impossible" << std::endl;
    }
    else if (intNum < 32 || intNum == 127) {
        std::cout << "char: non-displayable" << std::endl;
    }
    else {
        std::cout << "char: " << static_cast<char>(intNum) << std::endl;
    }
    
    std::cout << "int: " << intNum << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(num) << "f" << std::endl; 
    std::cout << "double: " << std::fixed << std::setprecision(2) << num << std::endl;
}



static void		minInfConvertion() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MIN << std::endl;
	std::cout << "float: " << __FLT_MIN__ << std::endl;
	std::cout << "double: " << __DBL_MIN__ << std::endl;
}


static void		maxInfConvertion() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MAX << std::endl;
	std::cout << "float: " << __FLT_MAX__ << std::endl;
	std::cout << "double: " << __DBL_MAX__ << std::endl;
}



static void		nanConvertion() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << 0 << std::endl;
	std::cout << "float: " << 0 << std::endl;
	std::cout << "double: " << 0 << std::endl;
}

static void		error() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << 0 << std::endl;
	std::cout << "float: " << 0 << std::endl;
	std::cout << "double: " << 0 << std::endl;
}



static void		checkInput(str input) {
	if (std::isprint(input[0]) && !std::isdigit(input[0])) {
		if (input.length() == 1)
			charConvertion(input);
		else if (input == "-inf" || input == "-inff")
			minInfConvertion();
		else if (input == "+inf" || input == "+inff")
			maxInfConvertion();
		else if (input == "nan" || input == "nanf")
			nanConvertion();
		else
			error();
	}
	else if (input[input.length() - 1] == 'f') {
		long unsigned int	i = 0;
		while (i < input.length() - 1 && (std::isdigit(input[i]) || input[i] == '.'))
			i++;
		if (i == input.length() - 1)
			floatConvertion(input);
		else
			error();
	}
	else if (input.find('.') != std::string::npos) {
		long unsigned int	i = 0;
		while (std::isdigit(input[i]) || input[i] == '.')
			i++;
		if (i == input.length())
			doubleConvertion(input);
		else
			error();
	}
	else if (std::isdigit(input[0])) {
		long unsigned int	i = 0;
		while (std::isdigit(input[i]))
			i++;
		if (i == input.length())
			intConvertion(input);
		else
			error();
	}
	else
		error();
}

void	ScalarConverter::convert(str &lit) {
	checkInput(lit);
}
