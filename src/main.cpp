#include "Newton.h"

int main()
{
    int degree;
	float start;
	std::optional<float> result;

    std::cout << "Enter the degree of polynomial: ";
    std::cin >> degree;
	std::cout << "Enter initial guess: ";
	std::cin >> start;

    Polynomial f(degree);

    return 0;
}
