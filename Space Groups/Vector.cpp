#include "Vector.h"
#include <iostream>
#include <math.h>

Vector::Vector(int dims) : dimensions(dims)
{
	components = new double[dimensions];
}

Vector::Vector(const Vector &vec) : dimensions(vec.dimensions) 
{
	components = new double[dimensions];
	components = vec.components;
}

Vector::Vector(const std::vector<double> comps) : dimensions(comps.size())
{
	components = new double[dimensions];
	setVectorComponents(comps);
}

Vector::~Vector() 
{
	delete components;
}

void Vector::setVectorComponents(const std::vector<double> &comps)
{
	if (comps.size() != dimensions)
	{
		std::cout << "Dimensions do not match. Given: " << comps.size() << " Expected: " << dimensions << std::endl;
		return;
	}

	if (components == nullptr) components = new double[comps.size()];

	for (int i = 0; i < dimensions; i++) 
	{
		components[i] = comps[i];
	}
}

double Vector::norm() 
{
	std::vector<double> comps;
	for (int i = 0; i < dimensions; i++)
	{
		comps.push_back(components[i]);
	}

	Vector v(comps);
	return v * v;
}

Vector Vector::operator+(const Vector &vec)
{
	if (dimensions != vec.dimensions)
	{
		throw std::invalid_argument("Dimensions do not match");
	}

	Vector vec2(vec.dimensions);

	for (int i = 0; i < vec.dimensions; i++) 
	{
		vec2.components[i] = components[i] + vec.components[i];
	}

	return vec2;
}

double Vector::operator*(const Vector &vec)
{
	if (dimensions != vec.dimensions)
	{
		if (dimensions != vec.dimensions)
		{
			throw std::invalid_argument("Dimensions do not match");
		}
	}

	double dot_product = 0;

	for (int i = 0; i < dimensions; i++)
	{
		dot_product += components[i] * vec.components[i];
	}

	return dot_product;
}

Vector& Vector::operator=(const Vector &vec)
{
	if (this != &vec)
	{
		dimensions = vec.dimensions;

		std::vector<double> comps;
		for (int i = 0; i < dimensions; i++)
		{
			comps.push_back(vec.components[i]);
		}
		setVectorComponents(comps);
	}
	return *this;
}

void Vector::print() 
{
	if (components == nullptr)
	{
		std::cout << "No components to print" << std::endl;
		return;
	}

	std::cout << "{";
	for (int i = 0; i < dimensions-1; i++) 
	{
		std::cout << components[i] << ", ";
	}
	std::cout << components[dimensions - 1] << "}" << std::endl;
}