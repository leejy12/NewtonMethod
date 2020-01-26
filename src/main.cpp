#include <iostream>
#include "Newton.h"

int main()
{
	int degree;
	std::cout << "Enter the degree of polynomial: ";
	std::cin >> degree;

	Polynomial f(degree);
	f.init();

	FindAllRoots(f);
	
	return 0;
} 
