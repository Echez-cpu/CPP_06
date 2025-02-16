#include "../includes/ScalarConverter.hpp"

static void		charConvertion(str input) {
	std::cout << "char: '" << input[0] << "'" << std::endl;
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
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
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
        std::cout << "char: '" << static_cast<char>(intNum) << "'" << std::endl;
    }
    
    std::cout << "int: " << intNum << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
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
        std::cout << "char: '" << static_cast<char>(intNum) << "'" << std::endl;
    }
    
    std::cout << "int: " << intNum << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl; 
    std::cout << "double: " << std::fixed << std::setprecision(1) << num << std::endl;
}


static void		minInfConvertion() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MIN << std::endl;
	std::cout << "float: " << __FLT_MIN__ << std::endl;
	std::cout << "double: " << __DBL_MIN__ << std::endl;
}


static bool isValidInt(const std::string &param, int &result) {
    char *end;
    errno = 0;
    long n = strtol(param.c_str(), &end, 10);
    
    if (errno == ERANGE || n > INT_MAX || n < INT_MIN) {
        return false;
    }
    
    result = static_cast<int>(n);
    return *end == '\0';  
}


static void		maxInfConvertion() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MAX << std::endl;
	std::cout << "float: " << __FLT_MAX__ << std::endl;
	std::cout << "double: " << __DBL_MAX__ << std::endl;
}



static void		nanConvertion() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int:  impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

static void		nanConvertion2() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int:  impossible" << std::endl;
	std::cout << "float: error: invalid input" << std::endl;
	std::cout << "double: error: invalid input" << std::endl;
}


static void		nanConvertion3() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: error: overflow or something else" << std::endl;
	std::cout << "float: error: invalid" << std::endl;
	std::cout << "double: error: invalid" << std::endl;
}



static bool isValidFloatFormat(const str  &input) {
    int dotCount = 0;
    for (long unsigned int i = 0; i < input.length(); i++) {
        if (input[i] == '.')
            dotCount++;
        else if (!std::isdigit(input[i]) && input[i] != 'f')  
            return false;
    }
    return dotCount <= 1;
}


static void		error() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << 0 << std::endl;
	std::cout << "float: " << 0 << std::endl;
	std::cout << "double: " << 0 << std::endl;
}



static void		checkInput(str input) {
	if (std::isprint(input[0]) && !std::isdigit(input[0]) && input[input.length() - 1] != 'f' && input.find('.') == std::string::npos) {
		
		if (input.length() == 1)
			charConvertion(input);

		else if (input == "nan")
			nanConvertion();				
			
		else if ((input[0] == '-' && std::isdigit(input[1]))) {
			int value;
    			if (!isValidInt(input, value))
        			nanConvertion3();
			else
			intConvertion(input);	
		}
				
		else
			error();
	}

            else if (input == "-inf" || input == "-inff")
			minInfConvertion();
	    else if (input == "+inf" || input == "+inff")
			maxInfConvertion();
	    else if (input == "nanf")
		       nanConvertion();
		
	else if (input[input.length() - 1] == 'f') {

	if (input[0] == '-' && isValidFloatFormat(input.substr(1)))
           		 floatConvertion(input);

		else if (!isValidFloatFormat(input))
		      nanConvertion2();
        				
		else
			floatConvertion(input);
	}
	else if (input.find('.') != std::string::npos) {

               if (input[0] == '-' && isValidFloatFormat(input.substr(1)))
           		 doubleConvertion(input);		
		
		else if (!isValidFloatFormat(input))
		      nanConvertion2();		
			
		else
			doubleConvertion(input);
	}

     else if (std::isdigit(input[0]) || (input[0] == '-' && std::isdigit(input[1]))) {
	    int value;
    	if (!isValidInt(input, value))
        	nanConvertion3();
			
	else
       	 intConvertion(input);
}
		
	else
		error();
}

void	ScalarConverter::convert(const str &lit) {
	checkInput(lit);
}





/*void ScalarConverter::convert(const std::string &literal) {
    char c;
    int i;
    float f;
    double d;

    if (literal.length() == 1 && !isdigit(literal[0])) {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } 
    else {
        char* end;
        double value = strtod(literal.c_str(), &end);

        if (*end && std::string(end) != "f") {
            std::cerr << "Conversion impossible" << std::endl;
            return;
        }

        i = static_cast<int>(value);
        f = static_cast<float>(value);
        d = static_cast<double>(value);
    }

    if (isprint(i))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else if (i >= 0 && i <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}*/
