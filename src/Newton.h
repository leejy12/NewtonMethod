#pragma once

#ifndef NEWTON_H
#define NEWTON_H

constexpr double EPSILON = 0.0000001;

#include <iostream>
#include <vector>
#include <optional>

struct NewtonMethodResult
{
    bool success;
    double answer;
    std::string reason;
};

class Polynomial
{
private:
    std::size_t _degree;
    std::vector<double> _vCoefficients;

public:
    Polynomial(const std::vector<float>& cff);

    double operator()(const double x) const;
    Polynomial Derivative() const;

    bool IsZeroFunction() const;

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& f);
};

NewtonMethodResult NewtonMethod(const Polynomial& f, const double ix);

#endif
