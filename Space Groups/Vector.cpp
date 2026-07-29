#include "Vector.h"
#include "Vector.h"
#include <iostream>

Vector::Vector(int dims) : dimensions(dims)
{
	components = new double[dims];
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

	int i;

	for (i = 0; i < comps.size(); i++) 
	{
		components[i] = comps[i];
	}
}

void Vector::setVectorComponents(const double* comps) 
{
	int size = 0;
	while (comps[size] != NULL) 
	{
		comps[size++];
	}

	if (size != dimensions)
	{
		std::cout << "Dimensions do not match. Given: " << size << " Expected: " << dimensions << std::endl;
		return;
	}

	for (int i = 0; i < size; i++) 
	{
		components[i] = comps[i];
	}
}

Vector Vector::operator+(const Vector &vec)
{
	Vector vec2(vec.dimensions);

	for (int i = 0; i < vec.dimensions; i++) 
	{
		vec2.components[i] = components[i] + vec.components[i];
	}

	return vec2;
}

void Vector::print() 
{
	std::cout << "{";
	for (int i = 0; i < dimensions-1; i++) 
	{
		std::cout << components[i] << ", ";
	}
	std::cout << components[dimensions - 1] << "}" << std::endl;
}