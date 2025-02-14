#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"


void identify(Base* p) {
    if (p == NULL) { 
        std::cout << "Pointer is NULL, cannot identify type." << std::endl;
        return;
    }

    
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "The pointer is of type A." << std::endl;
    }
    else if (dynamic_cast<B*>(p) != NULL) { 
        std::cout << "The pointer is of type B." << std::endl;
    }
    else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "The pointer is of type C." << std::endl;
    }
    else {
        std::cout << "Unknown type." << std::endl; // Handle unexpected types
    }
}
