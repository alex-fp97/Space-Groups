#pragma once
#include <vector>
#include <string>
#include <iostream>

class Vector {

	std::vector<double> v_elements;
	int dim1 = 1;
	int dim2 = 0;
	bool transposed = false;
	bool isEmpty = false;

public:
	Vector();
	Vector(int dimension);
	Vector(const Vector &vec);
	Vector(const std::vector<double>& comps);
	~Vector();

	void setVectorElements(const std::vector<double> &comps);
	
	Vector& transpose();
	double norm() const;
	int size() const { return dim2; }
	double getSum()
	{
		double sum = 0;
		for (int i = 0; i < dim2; i++)
		{
			sum += v_elements[i];
		}
		return sum;
	}
	
	Vector operator+(const Vector &vec);
	Vector operator-(const Vector& vec);
	double operator*(const Vector &vec);
	Vector operator*(double num);
	double operator|(const Vector& vec);
	Vector& operator=(const Vector &vec);
	Vector operator/(double num);
	double& operator[](int i);
	const double& operator[](int i) const;

	void addElement(double e);
	int getDim() const { return dim2; }
	const std::string dimsToString() const;
	void print() const;
	const bool empty() const { return isEmpty; }
};