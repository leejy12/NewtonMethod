#pragma once

#ifndef NEWTON_H
#define NEWTON_H

#define TOLERANCE       0.000001
#define EPSILON         0.00001
#define MAX_ITERATION   30

#include <vector>
#include <iostream>

enum
{
	FAIL = -123456789
};

class Polynomial
{
private:
	int degree;
	std::vector<float> coeff;

public:
	Polynomial(int deg);

	void init();
	void init(const std::vector<float>& cff);

	int getDegree() const;
	float operator() (float x) const;
	Polynomial derivative() const;

	friend std::ostream& operator<<(std::ostream& os, const Polynomial& f);
};

float NewtonMethod(const Polynomial& f, float ix);
void FindAllRoots(const Polynomial& f);

#endif
