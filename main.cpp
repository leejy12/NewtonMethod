#include <iostream>
#include <algorithm>
#include "Newton.h"

void findAllRoots(Polynomial& f)
{
	std::cout << std::endl;
	std::cout << "solving ";
	f.show();
	std::cout << "=0" << std::endl;

	int max_roots = f.getDegree();
	int roots_found = 0, idx = 0;
	float root;
	float range[2], allRoots[100];

	for (int i = 0; i < 10; i++) {

		range[0] = -100.0f + i * 0.1f;
		range[1] = -99.0f + i * 0.1f;

		while (range[1] < 100.0f) {

			if (f(range[0]) * f(range[1]) <= 0) {

				root = newtonMethod(f, range[0]);

				if (root != FAIL) {
					allRoots[idx++] = root;
					roots_found++;
				}

				range[0] = range[1];
				range[1] += 1.0f;
			}
			else {
				range[0] = range[1];
				range[1] += 1.0f;
			}
		}
	}

	if (roots_found == 0) {
		std::cout << "No real roots found." << std::endl;
		return;
	}

	// sort allRoots[]
	std::sort(std::begin(allRoots), std::begin(allRoots) + roots_found);

	int cnt = 0;
	for (int i = 0; i < roots_found; i++) {
		if (std::abs(allRoots[i] - allRoots[i - 1]) < EPSILON)
			continue;
		else
			cnt++;
	}

	std::cout << cnt << " real root(s) were found." << std::endl << std::endl;

	std::cout << "x=" << allRoots[0] << std::endl;
	for (int i = 1; i < roots_found; i++) {
		if (std::abs(allRoots[i] - allRoots[i - 1]) < EPSILON)
			continue;
		else
			std::cout << "x=" << allRoots[i] << std::endl;
	}
}

int main()
{
	int degree;
	std::cout << "Enter the degree of polynomial: ";
	std::cin >> degree;

	Polynomial f(degree);
	f.init();

	findAllRoots(f);
	
	return 0;
} 
