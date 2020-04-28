#include "Newton.h"
#include <cmath>

Polynomial::Polynomial(int deg)
    : _degree(deg)
{
	_coeff.resize(deg + 1);
	std::cout << "Enter " << _degree << " coefficients and a constant.\n";
	for (int i = 0; i < _degree + 1; i++)
		std::cin >> _coeff[i];
}

Polynomial::Polynomial(const std::vector<float>& cff)
    : _degree(cff.size() - 1), _coeff(cff)
{
}

int Polynomial::GetDegree() const
{
	return _degree;
}

float Polynomial::operator()(const float x) const
{
	float res = 0;
	for (int i = 0; i < _degree + 1; i++)
		res += _coeff[i] * pow(x, _degree - i);
	return res;
}

Polynomial Polynomial::Derivative() const
{
	std::vector<float> dv_coeff(_degree);

	// Power rule
	for (int i = 0; i < _degree; i++)
		dv_coeff[i] = (_degree - i) * _coeff[i];

	return Polynomial(dv_coeff);
}

std::ostream& operator<<(std::ostream& os, const Polynomial& f)
{
	for (int i = 0; i < f._degree; i++)
	{
		if (f._coeff[i] == 0)
		{
			if (f._coeff[i + 1] > 0)
				os << "+";
			continue;
		}
		if (f._coeff[i] == 1)
			os << "x";
		else if (f._coeff[i] == -1)
			os << "-x";
		else
			os << f._coeff[i] << "x";
		if (i != f._degree - 1)
			os << "^" << f._degree - i;
		if (f._coeff[i + 1] > 0)
			os << "+";
	}
	if (f._coeff[f._degree] != 0)
		os << f._coeff[f._degree];

	return os;
}

std::optional<float> NewtonMethod(const Polynomial& f, float ix)
{
<<<<<<< HEAD
	// initial guess is very close to root
	if (f(ix) < PRECISION)
		return ix;

	float x0 = ix, x1;
	float y, yprime;
	Polynomial fprime = f.Derivative();

	for (int i = 0; i < MAX_ITERATION; i++)
	{
		y = f(x0);
		yprime = fprime(x0);

		// Division By Zero
		if (std::abs(yprime) < EPSILON)
		{
			std::cout << "Division by zero\n";
			return {};
		}

		x1 = x0 - y / yprime;

		if (std::abs(x1 - x0) < PRECISION)
			return x1;
		else
			x0 = x1;
	}

	// Did not converge, return empty optional
	return {};
=======
    // initial guess is very close to root
    if (f(ix) < PRECISION)
        return ix;

    float x0 = ix, x1;
    float y, yprime;
    Polynomial fprime = f.Derivative();

    for (int i = 0; i < MAX_ITERATION; i++)
    {
        y = f(x0);
        yprime = fprime(x0);

        // Division By Zero
        if (std::abs(yprime) < EPSILON)
        {
            std::cout << "Division by zero\n";
            return {};
        }

        x1 = x0 - y / yprime;

        if (std::abs(x1 - x0) < PRECISION)
            return x1;
        else
            x0 = x1;
    }

    // Did not converge, return empty optional
    return {};
>>>>>>> e1db99a6ea4b648b63b6abda7f554fe68d63b924
}
