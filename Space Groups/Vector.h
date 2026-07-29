#pragma once
#include <vector>

class Vector {

	double* components;
	int dimensions = 0;
	

public:
	Vector(int dims);
	Vector(const Vector &vec);
	Vector(const std::vector<double> components);
	~Vector();

	void setVectorComponents(const std::vector<double> &comps);

	double norm();
	
	Vector operator+(const Vector &vec);
	double operator*(const Vector &vec);
	Vector& operator=(const Vector &vec);

	void print();
};