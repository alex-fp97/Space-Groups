#include "matr.h"
#include <sstream>
#include <iostream>
#include <algorithm>

Matrix::Matrix(){}

Matrix::Matrix(const std::vector<std::vector<double>>& elems)
{
	std::vector<std::vector<double>> elements = elems;
	std::vector<int> v_sizes;
	for (int i = 0; i < elements.size(); i++)
	{
		v_sizes.push_back(elements[i].size());
	}

	int maxSize = *std::max_element(v_sizes.begin(), v_sizes.end());

	for (std::vector<double>& v : elements)
	{
		if (v.size() < maxSize)
		{
			int reps = maxSize - static_cast<int>(v.size());
			for (int i = 0; i < reps; i++)
			{
				v.push_back(0);
			}
		}
	}

	m = static_cast<int>(elements.size());
	n = maxSize;
	
	m_elements = new double*[m];
	
	for (int i = 0; i < m; i++)
	{
		m_elements[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			m_elements[i][j] = elements[i][j];
		}
	}
}

Matrix::Matrix(int m, int n) : m(m), n(n)
{
	m_elements = new double* [m];
	for (int i = 0; i < m; i++)
	{
		m_elements[i] = new double[n];
	}
}

Matrix::Matrix(const Matrix& M) : m(M.m), n(M.n)
{
	m_elements = new double* [m];
	for (int i = 0; i < m; i++)
	{
		m_elements[i] = new double[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			m_elements[i][j] = M.m_elements[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < m; i++)
	{
		delete[] m_elements[i];
	}
	delete[] m_elements;
}

Matrix& Matrix::operator=(const Matrix& M)
{
	if (this == &M) return *this;
	Matrix tmp(M);
	std::swap(m, tmp.m);
	std::swap(n, tmp.n);
	std::swap(m_elements, tmp.m_elements);
	return *this;
}

Matrix Matrix::operator+(const Matrix& M)
{

	if (m != M.m || n != M.n)
	{
		std::cout << "Dimensions do not match ( " << dimsToString() << ", " << M.dimsToString() << " )" << std::endl;
		Matrix Q(0, 0);
		return Q;
	}

	Matrix S(m, n);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			S.m_elements[i][j] = m_elements[i][j] + M.m_elements[i][j];
		}
	}

	return S;
}

Matrix Matrix::operator*(const Matrix& M)
{
	if (n != M.m)
	{
		std::cout << "Dimensions do not match ( " << dimsToString() << ", " << M.dimsToString() << " )" << std::endl;
		Matrix Q(0, 0);
		return Q;
	}

	Matrix S(m, M.n);

	double **S_elements = new double* [S.m];
	for (int i = 0; i < S.m; i++)
	{
		S_elements[i] = new double[S.n];
		std::fill(S_elements[i], S_elements[i] + S.n, 0);
	}

	S.m_elements = S_elements;

	for (int i = 0; i < S.m; i++)
	{
		for (int j = 0; j < S.n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				S.m_elements[i][j] += m_elements[i][k] * M.m_elements[k][j];
			}
		}
	}

	return S;
}

void Matrix::T()
{
	double** elems = new double*[n];
	for (int i = 0; i < n; i++)
	{
		elems[i] = new double[m];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			elems[j][i] = m_elements[i][j];
		}
	}

	m_elements = elems;

	int temp = m;
	m = n;
	n = temp;
}

Matrix Matrix::transpose()
{
	
	Matrix newM(n, m);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			newM.m_elements[j][i] = m_elements[i][j];
		}
	}

	return newM;
}

std::string Matrix::dimsToString() const
{
	std::stringstream toReturn;
	toReturn << '(' << m << " x " << n << ')';
	return toReturn.str();
}

void Matrix::print() const
{
	for (int i = 0; i < m; i++)
	{
		if (i > 0 && i < m - 1) std::cout << "|";
		else std::cout << "[";
		
		for (int j = 0; j < n - 1; j++)
		{
			std::cout << m_elements[i][j] << ", ";
		}
		
		if (i > 0 && i < m - 1) std::cout << m_elements[i][n-1] << "|" << std::endl;
		else std::cout << m_elements[i][n-1] << "]" << std::endl;
	}
}
