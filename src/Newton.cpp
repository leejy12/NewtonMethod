#include "Newton.h"
#include <cmath>

Polynomial::Polynomial(const std::vector<double>& cff)
    : _degree(cff.size() - 1), _vCoefficients(cff)
{
}

double Polynomial::operator()(const double x) const
{
    float res = 0;
    for (int i = 0; i < _degree + 1; i++)
        res += _vCoefficients[i] * pow(x, _degree - i);
    return res;
}

Polynomial Polynomial::Derivative() const
{
    // Handle constant functions.
    if (_degree == 0)
        return Polynomial({0});

    std::vector<double> dv_coeff(_degree);

    // Power rule
    for (int i = 0; i < _degree; i++)
        dv_coeff[i] = (_degree - i) * _vCoefficients[i];

    return Polynomial(dv_coeff);
}

bool Polynomial::IsZeroFunction() const
{
    return (_degree == 0) && (_vCoeffecients[0] < EPSILON);
}

std::ostream& operator<<(std::ostream& os, const Polynomial& f)
{
    if (f.IsZeroFunction())
    {
        os << "0";
        return os;
    }

    for (int i = 0; i < f._degree; i++)
    {
        if (f._vCoefficients[i] == 0)
        {
            if (f._vCoefficients[i + 1] > 0)
                os << "+";
            continue;
        }
        if (f._vCoefficients[i] == 1)
            os << "x";
        else if (f._vCoefficients[i] == -1)
            os << "-x";
        else
            os << f._vCoefficients[i] << "x";
        if (i != f._degree - 1)
            os << "^" << f._degree - i;
        if (f._vCoefficients[i + 1] > 0)
            os << "+";
    }
    if (f._vCoefficients[f._degree] != 0)
        os << f._vCoefficients[f._degree];

    return os;
}

NewtonMethodResult NewtonMethod(const Polynomial& f, const double ix)
{
    // Check if f is a zero function.
    if (f.IsZeroFunction())
        return {false, NAN, "Zero Function"};

    // initial guess is very close to root
    if (std::abs(f(ix)) < EPSILON)
        return ix;

    double x0 = ix, x1, y, yprime;
    const Polynomial fprime = f.Derivative();

    static constexpr int MAX_ITERATION = 30;
    for (int i = 0; i < MAX_ITERATION; i++)
    {
        y = f(x0);
        yprime = fprime(x0);

        // Division By Zero
        if (std::abs(yprime) < EPSILON)
        {
            return {false, NAN, L"Division By Zero"};
        }

        x1 = x0 - y / yprime;

        if (std::abs(x1 - x0) < PRECISION)
            return x1;
        else
            x0 = x1;
    }

    return {false, NAN, L"Did Not Converge"};
}
