#pragma once

#define TOLERANCE       0.000001
#define EPSILON         0.0000001
#define MAX_ITERATION   30

#include <vector>

class Polynomial {
private:
    int degree;
    std::vector<float> coeff;

public:
    Polynomial(int deg);

    void init();

    void init(std::vector<float>& cff);

    float operator() (float x) const;

    void show() const;

    Polynomial derivative() const;
};

float newtonMethod(Polynomial& f, float ix);