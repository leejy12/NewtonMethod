#include <iostream>
#include <cmath>        // for pow(), abs()
#include "Newton.h"

Polynomial::Polynomial(int deg)
	: degree(deg)
{
	coeff.resize(deg + 1);
}

void Polynomial::init() {
	std::cout << "Enter " << degree << " coefficients and a constant." << std::endl;
	for (int i = 0; i < degree + 1; i++) {
		std::cin >> coeff[i];
	}
}

void Polynomial::init(std::vector<float>& cff) {
	for (int i = 0, size = cff.size(); i < size; i++)
		coeff[i] = cff[i];
}

int Polynomial::getDegree() const {
	return degree;
}

float Polynomial::operator() (float x) const {
	float res = 0;
	for (int i = 0; i < degree + 1; i++) {
		res += coeff[i] * pow(x, degree - i);
	}
	return res;
}

void Polynomial::show() const {
	for (int i = 0; i < degree; i++) {
		if (coeff[i] == 0) {
			if (coeff[i + 1] > 0) std::cout << "+";
			continue;
		}
		if (coeff[i] == 1)
			std::cout << "x";
		else if (coeff[i] == -1)
			std::cout << "-x";
		else
			std::cout << coeff[i] << "x";
		if (i != degree - 1)
			std::cout << "^" << degree - i;
		if (coeff[i + 1] > 0)
			std::cout << "+";
	}
	if (coeff[degree] != 0)
		std::cout << coeff[degree];
	// std::cout << std::endl;
}

Polynomial Polynomial::derivative() const {
	Polynomial derived(degree - 1);
	std::vector<float> dv_coeff(degree);

	for (int i = 0; i < degree; i++) {
		dv_coeff[i] = (degree - i) * coeff[i];  // Power rule
	}

	derived.init(dv_coeff);
	return derived;
}

float newtonMethod(Polynomial& f, float ix) {

	if (f(ix) == 0.0f) {
		// std::cout << "f(" << ix << ") is close to 0." << std::endl;
		return ix;
	}

	float x0 = ix, x1;
	float y, yprime;
	Polynomial fprime = f.derivative();

	for (int i = 0; i < MAX_ITERATION; i++) {
		y = f(x0);
		yprime = fprime(x0);

		// Division By Zero
		if (std::abs(yprime) < EPSILON) {
			return FAIL;
		}

		x1 = x0 - y / yprime;
		// std::cout << x1 << std::endl; to see 

		if (std::abs(x1 - x0) < TOLERANCE) {
			return x1;
		}
		else {
			x0 = x1;
		}
	}
	// Did not converge
	return FAIL;
}
