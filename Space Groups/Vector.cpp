#include "Vector.h"
#include <iostream>
#include <math.h>
#include <string>

Vector::Vector(int dimension) : v_elements(std::vector<double>(dimension)) 
{
	dim2 = dimension;
}

Vector::Vector(const Vector &vec) : dim2(vec.dim2) 
{
	v_elements.resize(dim2);
	v_elements = vec.v_elements;
}

Vector::Vector(const std::vector<double> comps) : dim2(comps.size())
{
	v_elements = std::vector<double>(comps.begin(), comps.end());
}

Vector::~Vector() {}

void Vector::setVectorElements(const std::vector<double> &comps)
{
	if (comps.size() != dim2)
	{
		throw std::invalid_argument("dim do not match. Expected: " + std::to_string(dim2) + ", Given: " + std::to_string(comps.size()));
	}

	v_elements = std::vector<double>(comps.begin(), comps.end());
}

double Vector::norm() const
{
	std::vector<double> comps;
	for (int i = 0; i < dim2; i++)
	{
		comps.push_back(v_elements[i]);
	}

	Vector v(comps);
	return v * v;
}

Vector Vector::operator+(const Vector &vec)
{
	if (dim2 != vec.dim2)
	{
		throw std::invalid_argument("dim do not match");
	}

	Vector vec2(vec.dim2);

	for (int i = 0; i < vec.dim2; i++) 
	{
		vec2.v_elements[i] = v_elements[i] + vec.v_elements[i];
	}

	return vec2;
}

double Vector::operator*(const Vector &vec)
{
	if (dim2 != vec.dim2)
	{
		if (dim2 != vec.dim2)
		{
			throw std::invalid_argument("dim do not match");
		}
	}

	double dot_product = 0;

	for (int i = 0; i < dim2; i++)
	{
		dot_product += v_elements[i] * vec.v_elements[i];
	}

	return sqrt(dot_product);
}

Vector& Vector::operator=(const Vector &vec)
{
	if (this != &vec)
	{
		dim2 = vec.dim2;

		std::vector<double> comps;
		for (int i = 0; i < dim2; i++)
		{
			comps.push_back(vec.v_elements[i]);
		}
		setVectorElements(comps);
	}
	return *this;
}

double& Vector::operator[](int i)
{
	if (i > dim2-1) throw std::invalid_argument("Index is larger than current vector dimension");
	if (i < 0) throw std::invalid_argument("Index is negative");

	return v_elements[i];
}

const double& Vector::operator[](int i) const
{
	if (i > dim2- 1) throw std::invalid_argument("Index is larger than current vector dimension");
	if (i < 0) throw std::invalid_argument("Index is negative");

	return v_elements[i];
}

void Vector::print() const
{
	for (int i = 0; i < dim1; i++)
	{
		std::cout << "[";
		int j;
		for (j = 0; j < dim2 - 1; j++)
		{
			std::cout << v_elements[i][j] << ", ";
		}
		std::cout << v_elements[i][dim2 - 1] << "]" << std::endl;
	}
}
