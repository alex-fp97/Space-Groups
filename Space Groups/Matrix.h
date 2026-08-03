#pragma once
#include <vector>
#include <string>

class Vector;

class Matrix {

	std::vector<Vector> m_elements;
	int dim1 = 0;
	int dim2 = 0;

public:

	Matrix();
	Matrix(const std::vector<Vector> &elems);
	Matrix(const Matrix& m);
	~Matrix();

	void setDims(int m, int n);
	void addCol(const Vector& v) { m_elements.push_back(v); }
	Vector getRow(int i) const;
	Vector getCol(int i) const;
	Vector& row(int i);
	Vector& col(int i);
	void T();
	Matrix transpose();

	double normOne();
	double normInf();
	double normTwo();

	Matrix operator+(const Matrix& m);
	Matrix operator*(const Matrix& m);
	Vector operator*(const Vector& v);
	Matrix& operator=(const Matrix& m);

	std::string dimsToString() const;
	int getDim1() const { return dim1; }
	int getDim2() const { return dim2; }
	void print() const;
};