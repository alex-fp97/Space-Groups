#include "Vector.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

Vector::Vector() : isEmpty(true) {};

Vector::Vector(int dimension) : dim2(dimension) {}

Vector::Vector(const Vector &vec) : dim2(vec.dim2)
{
	v_elements = vec.v_elements;
}

Vector::Vector(const std::vector<double>& comps) : dim2(comps.size()), v_elements(comps) {}

Vector::~Vector() {}

void Vector::setVectorElements(const std::vector<double> &comps)
{
	if (comps.size() != dim2)
	{
		throw std::invalid_argument("Dimensions do not match. Expected: " + std::to_string(dim2) + ", Given: " + std::to_string(comps.size()));
	}

	v_elements = std::vector<double>(comps.begin(), comps.end());
}

Vector& Vector::transpose()
{
	transposed = !transposed;
	return *this;
}

double Vector::norm() const
{
	std::vector<double> comps;
	for (int i = 0; i < dim2; i++)
	{
		comps.push_back(v_elements[i]);
	}

	Vector v(comps);
	return sqrt(v * v);
}

Vector Vector::operator+(const Vector &vec)
{
	if (dim2 != vec.dim2)
	{
		throw std::invalid_argument("Dimensions do not match ( " + dimsToString() + ", " + vec.dimsToString() + " )");
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
			throw std::invalid_argument("Dimensions do not match ( " + dimsToString() + ", " + vec.dimsToString() + " )");
		}
	}

	double dot_product = 0;

	for (int i = 0; i < dim2; i++)
	{
		dot_product += v_elements[i] * vec.v_elements[i];
	}

	return dot_product;
}

Vector Vector::operator*(double num)
{
	std::vector<double> elems = v_elements;

	for (int i = 0; i < elems.size(); i++)
	{
		elems[i] = elems[i] * num;
	}

	Vector v(elems);

	return v;
}

Vector& Vector::operator=(const Vector &vec)
{
	if (this != &vec)
	{
		dim2 = vec.dim2;
		isEmpty = vec.isEmpty;

		std::vector<double> comps;
		for (int i = 0; i < dim2; i++)
		{
			comps.push_back(vec.v_elements[i]);
		}
		setVectorElements(comps);
	}

	return *this;
}

Vector Vector::operator/(double num)
{
	std::vector<double> elems = v_elements;

	for (int i = 0; i < elems.size(); i++)
	{
		elems[i] = elems[i] / num;
	}

	Vector v(elems);

	return v;
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

void Vector::addElement(double e)
{
	v_elements.push_back(e); 
	dim2++;
	std::cout << "success" << std::endl;
}

const std::string Vector::dimsToString() const
{
	std::stringstream toReturn;
	toReturn << '(' << dim1 << " x " << dim2 << ')';
	return toReturn.str();
}

void Vector::print() const
{
	int m;
	int n;

	if (transposed) 
	{
		m = dim2;
		n = dim1;
	}
	else
	{
		m = dim1;
		n = dim2;
	}

	for (int i = 0; i < m; i++)
	{
		int j = 0;
		std::cout << "[";
		for (int j = 0; j < n - 1; j++)
		{
			std::cout << v_elements[j] << ", ";
		}
		if (transposed)	std::cout << v_elements[i] << "]" << std::endl;
		else std::cout << v_elements[dim2-1] << "]" << std::endl;
	}
}
