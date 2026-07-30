#include <iostream>
#include "Matrix.h"
#include <string>
#include <sstream>

Matrix::Matrix() {}
Matrix::Matrix(const std::vector<Vector> &elements) : m_elements(elements) 
{
	dim1 = elements.size();
	dim2 = elements[0].size();
	transpose();
}
Matrix::Matrix(const Matrix &m) : m_elements(m.m_elements)
{
	dim1 = m.dim1;
	dim2 = m.dim2;
}
Matrix::~Matrix() {}

void Matrix::transpose()
{
	std::vector<Vector> vecsToTranspose(dim2);
	
	for (int i = 0; i < dim2; i++) 
	{
		for (int j = 0; j < dim1; j++)
		{
			vecsToTranspose[i].addElement(m_elements[j][i]);
		}
	}

	m_elements = std::vector<Vector>(vecsToTranspose.begin(), vecsToTranspose.end());

	int temp = dim1;
	dim1 = dim2;
	dim2 = temp;
}

Vector Matrix::getRow(int i)
{
	if (i > dim1 - 1) throw std::invalid_argument("Index is larger than current dimensions.");
	if (i < 0) throw std::invalid_argument("Index is negative.");
	return m_elements[i];
}

Vector Matrix::getCol(int i)
{
	if (i > dim2 - 1) throw std::invalid_argument("Index is larger than current dimensions.");
	if (i < 0) throw std::invalid_argument("Index is negative.");
	
	Vector column(dim1);

	for (int j = 0; j < dim1; j++)
	{
		column[j] = m_elements[j][i];
	}

	return column;
}

Matrix Matrix::operator+(const Matrix& m)
{
	if (dim1 != m.dim1 || dim2 != m.dim2)
	{
		int dim1 = m.dim1;
		int dim2 = m.dim2;
		throw std::invalid_argument("Matrix dimensions do not match (" + dimsToString() + "and "+ m.dimsToString()+ ")");
	}

	Matrix newM(m);

	for (int i = 0; i < dim1; i++)
	{
		newM.m_elements[i] = m_elements[i] + m.m_elements[i];
	}

	return newM;
}

Matrix Matrix::operator*(const Matrix& m)
{
	if (dim2 != m.dim1)
	{
		int dim1 = m.dim1;
		int dim2 = m.dim2;
		throw std::invalid_argument("Matrix dimensions do not match (" + dimsToString() + "and " + m.dimsToString() + ")");
	}

	Matrix newM;

	newM.setDims(dim1, m.dim2);

	for (int i = 0; i < dim1; i++)
	{
		Vector v;
		double prod = 0;
		for (int j = 0; j < dim2; j++)
		{
			prod += m_elements[i][j] * m_elements[j][i];
			v.addElement(prod);
		}
		newM.addCol(v);
	}

}

Matrix& Matrix::operator=(const Matrix& m)
{
	if (this != &m)
	{
		dim1 = m.dim1;
		dim2 = m.dim2;

		std::vector<Vector> vecs;
		for (int i = 0; i < dim1; i++)
		{
			vecs.push_back(m.m_elements[i]);
		}
		m_elements = std::vector<Vector>(vecs.begin(), vecs.end());
	}
	return *this;
}

std::string Matrix::dimsToString() const
{
	std::stringstream toReturn;
	toReturn << '(' << dim1 << " x " << dim2 << ')';
	return toReturn.str();
}

void Matrix::print() const
{
	for (int i = 0; i < dim1; i++)
	{
		std::cout << "[";
		int j;
		for (j = 0; j < dim2 - 1; j++)
		{
			std::cout << m_elements[i][j] << ", ";
		}
		std::cout << m_elements[i][dim2-1] << "]" << std::endl;
	}
}