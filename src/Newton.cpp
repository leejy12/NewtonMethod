#include <iostream>
#include <cmath>
#include <algorithm>
#include "Newton.h"

Polynomial::Polynomial(int deg)
	: degree(deg)
{
	coeff.resize(deg + 1);
}

void Polynomial::init()
{
	std::cout << "Enter " << degree << " coefficients and a constant." << std::endl;
	for (int i = 0; i < degree + 1; i++)
		std::cin >> coeff[i];
}

void Polynomial::init(const std::vector<float>& cff)
{
	for (int i = 0, size = cff.size(); i < size; i++)
		coeff[i] = cff[i];
}

int Polynomial::getDegree() const
{
	return degree;
}

float Polynomial::operator() (float x) const
{
	float res = 0;
	for (int i = 0; i < degree + 1; i++)
		res += coeff[i] * pow(x, degree - i);
	return res;
}

Polynomial Polynomial::derivative() const
{
	Polynomial derived(degree - 1);
	std::vector<float> dv_coeff(degree);

	for (int i = 0; i < degree; i++)
		dv_coeff[i] = (degree - i) * coeff[i];  // Power rule

	derived.init(dv_coeff);
	return derived;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& f)
{
	int degree = f.getDegree();
	for (int i = 0; i < degree; i++)
	{
		if (f.coeff[i] == 0)
		{
			if (f.coeff[i + 1] > 0)
				os << "+";
			continue;
		}
		if (f.coeff[i] == 1)
			os << "x";
		else if (f.coeff[i] == -1)
			os << "-x";
		else
		os << f.coeff[i] << "x";
		if (i != degree - 1)
			os << "^" << degree - i;
		if (f.coeff[i + 1] > 0)
			os << "+";
	}
	if (f.coeff[degree] != 0)
		os << f.coeff[degree];

	return os;
}

float NewtonMethod(const Polynomial& f, float ix)
{
	if (f(ix) == 0.0f)
		return ix;

	float x0 = ix, x1;
	float y, yprime;
	Polynomial fprime = f.derivative();

	for (int i = 0; i < MAX_ITERATION; i++)
	{
		y = f(x0);
		yprime = fprime(x0);

		// Division By Zero
		if (std::abs(yprime) < EPSILON)
			return FAIL;

		x1 = x0 - y / yprime;

		if (std::abs(x1 - x0) < TOLERANCE)
			return x1;
		else
			x0 = x1;
	}
	// Did not converge
	return FAIL;
}

void FindAllRoots(const Polynomial& f)
{
	std::cout << "\nsolving " << f << "=0\n";

	int max_roots = f.getDegree();
	int roots_found = 0, idx = 0;
	float root;
	float range[2], allRoots[100];

	for (int i = 0; i < 10; i++)
	{
		range[0] = -100.0f + i * 0.1f;
		range[1] = -99.0f + i * 0.1f;

		while (range[1] < 100.0f)
		{
			if (f(range[0]) * f(range[1]) <= 0)
			{
				root = NewtonMethod(f, range[0]);
				if (root != FAIL) 
				{
					allRoots[idx++] = root;
					roots_found++;
				}
				range[0] = range[1];
				range[1] += 1.0f;
			}
			else
			{
				range[0] = range[1];
				range[1] += 1.0f;
			}
		}
	}

	if (roots_found == 0)
	{
		std::cout << "No real roots found.\n";
		return;
	}

	// sort allRoots[]
	std::sort(std::begin(allRoots), std::begin(allRoots) + roots_found);

	int cnt = 0;
	for (int i = 0; i < roots_found; i++)
	{
		if (std::abs(allRoots[i] - allRoots[i - 1]) < EPSILON)
			continue;
		else
			cnt++;
	}

	std::cout << cnt << " real root(s) were found.\n\n";
	std::cout << "x=" << allRoots[0] << '\n';
	for (int i = 1; i < roots_found; i++)
	{
		if (std::abs(allRoots[i] - allRoots[i - 1]) < EPSILON)
			continue;
		else
			std::cout << "x=" << allRoots[i] << '\n';
	}
}
