#include "Newton.h"
#include <cmath>

Polynomial::Polynomial(int deg) : _degree(deg)
{
    _coeff.resize(deg + 1);
    std::cout << "Enter " << _degree << " coefficients and a constant.\n";
    for (int i = 0; i < _degree + 1; i++)
        std::cin >> _coeff[i];
}

Polynomial::Polynomial(const std::vector<float>& cff) : _coeff(cff)
{
}

int Polynomial::GetDegree() const
{
    return _degree;
}

float Polynomial::operator()(float x) const
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
    int degree = f.GetDegree();
    for (int i = 0; i < degree; i++)
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
        if (i != degree - 1)
            os << "^" << degree - i;
        if (f._coeff[i + 1] > 0)
            os << "+";
    }
    if (f._coeff[degree] != 0)
        os << f._coeff[degree];

    return os;
}

std::optional<float> NewtonMethod(const Polynomial& f, float ix)
{
    // initial guess is very close to root
    if (f(ix) < EPSILON)
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
            return {};

        x1 = x0 - y / yprime;

        if (std::abs(x1 - x0) < TOLERANCE)
            return x1;
        else
            x0 = x1;
    }

    // Did not converge, return empty optional
    return {};
}
