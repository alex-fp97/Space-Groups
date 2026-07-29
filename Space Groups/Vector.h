#pragma once
#include <vector>

class Vector {

	double* components;
	int dimensions = 0;

public:
	Vector(int dims);
	~Vector();

	void setVectorComponents(const std::vector<double> &comps);
	void setVectorComponents(const double* comps);

	Vector operator+(const Vector &vec);

	void print();
};