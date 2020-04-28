#include "Newton.h"

int main()
{
	int degree;
	float start;
	std::optional<float> result;

	std::cout << "Enter the degree of polynomial: ";
	std::cin >> degree;
	Polynomial f(degree);

	std::cout << "Enter starting value: ";
	std::cin >> start;

	std::cout << "Solving " << f << "=0 using Newton's method starting at x0 = " << start << '\n';
	std::cout << "Result\n";
	result = NewtonMethod(f, start);

	if (result)
		std::cout << "x = " << result.value() << '\n';
	else
		std::cout << "Failed to converge.\n";

	return 0;
}
