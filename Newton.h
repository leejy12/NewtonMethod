#ifndef NEWTON_H
#define NEWTON_H

#define TOLERANCE       0.000001
#define EPSILON         0.00001
#define MAX_ITERATION   30

#include <vector>

enum {
	FAIL = -123456789
};

class Polynomial {
private:
	int degree;
	std::vector<float> coeff;

public:
	Polynomial(int deg);

	void init();

	void init(std::vector<float>& cff);

	int getDegree() const;

	float operator() (float x) const;

	void show() const;

	Polynomial derivative() const;
};

float newtonMethod(Polynomial& f, float ix);

#endif
