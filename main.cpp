#include <iostream>
#include "Newton.h"

int main()
{
    int degree;
    float x0;
    std::cout << "Enter the degree of polynomial: ";
    std::cin >> degree;

    Polynomial f(degree);
    f.init();
    f.show();

    std::cout << "Enter starting x: ";
    std::cin >> x0;

    std::cout << newtonMethod(f, x0) << std::endl;
    
    return 0;
}
