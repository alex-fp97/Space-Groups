#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include <string>
#include <sstream>
#include <algorithm>

Matrix::Matrix() : dim1(0), dim2(0) {}

Matrix::Matrix(const std::vector<Vector> &elems) 
{
	std::vector<Vector> elements = elems;
	std::vector<int> v_sizes;
	for (int i = 0; i < elements.size(); i++)
	{
		v_sizes.push_back(elements[i].size());
	}
	
	int maxSize = *std::max_element(v_sizes.begin(), v_sizes.end());
	for (Vector& v : elements)
	{
		if (v.size() < maxSize)
		{
			int reps = maxSize - static_cast<int>(v.size());
			for (int i = 0; i < reps; i++)
			{
				v.addElement(0);
			}
		}
	}

	dim1 = static_cast<int> (elements.size());
	dim2 = maxSize;
	m_elements = elements;
	T();
}

Matrix::Matrix(const Matrix& m) : m_elements(m.m_elements), dim1(m.dim1), dim2(m.dim2) {}

Matrix::~Matrix() {}

void Matrix::T()
{
	std::vector<Vector> vecsToTranspose(dim2);

	for (int i = 0; i < dim2; i++)
	{
		for (int j = 0; j < dim1; j++)
		{
			vecsToTranspose[i].addElement(m_elements[j][i]);
		}
	}

	m_elements = vecsToTranspose;
	
	int temp = dim1;
	dim1 = dim2;
	dim2 = temp;

}

Matrix Matrix::transpose()
{
	Matrix newM(*this);
	std::vector<Vector> vecsToTranspose(dim2);
	
	for (int i = 0; i < dim2; i++) 
	{
		for (int j = 0; j < dim1; j++)
		{
			vecsToTranspose[i].addElement(m_elements[j][i]);
		}
	}

	newM.m_elements = std::vector<Vector>(vecsToTranspose.begin(), vecsToTranspose.end());

	int temp = newM.dim1;
	newM.dim1 = newM.dim2;
	newM.dim2 = temp;


	return newM;
}

double Matrix::normOne()
{
	std::vector<double> colSums(dim2);

	for (int i = 0; i < dim2;)
	{
		colSums[i] = getCol(i).getSum();
	}

	return *std::max_element(colSums.begin(), colSums.end());
}

double Matrix::normInf()
{
	std::vector<double> rowSums(dim2);

	for (int i = 0; i < dim2;)
	{
		rowSums[i] = getRow(i).getSum();
	}

	return *std::max_element(rowSums.begin(), rowSums.end());
}

double Matrix::normTwo()
{
	std::vector<double> v(dim2, 0);
	v[0] = 1;
	
	Vector vec(v);

	return ((*this) * vec).norm();
}

void Matrix::setDims(int d1, int d2)
{
	dim1 = d1;
	dim2 = d2;

	m_elements.clear();

	m_elements = std::vector<Vector>(dim1);

	for (int i = 0; i < dim1; i++)
	{
		m_elements[i] = Vector (dim2);
	}
}

Vector Matrix::getRow(int i) const
{
	if (i > dim1 - 1) throw std::invalid_argument("Index is larger than current dimensions.");
	if (i < 0) throw std::invalid_argument("Index is negative.");
	return m_elements[i];
}

Vector Matrix::getCol(int i) const
{
	if (i > dim2 - 1) throw std::invalid_argument("Index is larger than current dimensions.");
	if (i < 0) throw std::invalid_argument("Index is negative.");
	
	Vector column(dim1);

	for (int j = 0; j < dim1; j++)
	{
		column[j] = m_elements[j][i];
	}

	column.transpose();

	return column;
}

Vector& Matrix::row(int i)
{
	return m_elements[i];
}

Vector& Matrix::col(int i)
{
	return this->transpose().m_elements[i];
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
		throw std::invalid_argument("Matrix dimensions do not match (" + dimsToString() + "and " + m.dimsToString() + ")");
	}

	Matrix toReturn;
	toReturn.setDims(dim1, m.dim2);

	for (int i = 0; i < dim1; i++)
	{
		for (int j = 0; j < m.dim2; j++)
		{
			toReturn.m_elements[i][j] = getRow(i) * m.getCol(j);
		}
	}
	return toReturn;
}

Vector Matrix::operator*(const Vector& v)
{

	if (dim2 != v.getDim())
	{
		throw std::invalid_argument("Dimensions do not match. Matrix: " + dimsToString() + ", Vector: " + v.dimsToString() + ".");
	}

	Vector toReturn(dim1);

	for (int i = 0; i < dim1; i++)
	{
		toReturn[i] = getRow(i) * v;
	}

	return toReturn;
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