#pragma once
#include <vector>
#include <string>

class Matrix {


	double **m_elements = nullptr;
	int m = 0;
	int n = 0;

public:
	Matrix();
	Matrix(const std::vector<std::vector<double>>& elems);
	Matrix(int m, int n);
	Matrix(const Matrix& m);
	~Matrix();

	Matrix& operator=(const Matrix& M);
	Matrix operator+(const Matrix& M);
	Matrix operator*(const Matrix& M);

	void T();
	Matrix transpose();
	std::string dimsToString() const;
	void print() const;

};