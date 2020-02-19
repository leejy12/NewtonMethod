#pragma once

#ifndef NEWTON_H
#define NEWTON_H

#define PRECISION 0.000001
#define EPSILON 0.00001
#define MAX_ITERATION 30

#include <iostream>
#include <vector>
#include <optional>

class Polynomial
{
private:
    int _degree;
    std::vector<float> _coeff;

public:
    Polynomial(int deg);
    Polynomial(const std::vector<float>& cff);

    int GetDegree() const;
    float operator()(const float x) const;
    Polynomial Derivative() const;

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& f);
};

std::optional<float> NewtonMethod(const Polynomial& f, float ix);

#endif
