#pragma once
#include <vector>
#include "Vector.h"
#include <string>

class Matrix {

	std::vector<Vector> m_elements;
	int dim1;
	int dim2;

public:

	Matrix();
	Matrix(const std::vector<Vector> &elements);
	Matrix(const Matrix& m);
	~Matrix();

	void setDims(int m, int n) { dim1 = m; dim2 = n; }
	void addCol(const Vector& v) { m_elements.push_back(v); }
	Vector getRow(int i);
	Vector getCol(int i);
	void transpose();

	Matrix operator+(const Matrix& m);
	Matrix operator*(const Matrix& m);
	Matrix& operator=(const Matrix& m);

	std::string dimsToString() const;
	int getDim1() const { return dim1; }
	int getDim2() const { return dim2; }
	void print() const;
};