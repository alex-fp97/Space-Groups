#pragma once
#include <vector>

class Vector {

	std::vector<double> v_elements;
	int dim1 = 1;
	int dim2 = 0;

public:
	Vector() {}
	Vector(int dimension);
	Vector(const Vector &vec);
	Vector(const std::vector<double> v_elements);
	~Vector();

	void setVectorElements(const std::vector<double> &comps);

	double norm() const;
	int size() const { return dim2; }
	
	Vector operator+(const Vector &vec);
	double operator*(const Vector &vec);
	Vector& operator=(const Vector &vec);
	double& operator[](int i);
	const double& operator[](int i) const;

	void addElement(double e) { v_elements.push_back(e); dim2++; }

	void print() const;
};