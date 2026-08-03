#include <iostream>
#include "matr.h"
int main() {

	std::vector<double> v1 = { 0, 1 };
	std::vector<double> v2 = { 2, 1 };
	std::vector<double> v3 = { 4, 3 };

	std::vector<std::vector<double>> vec1 = { v1, v2 };
	std::vector<std::vector<double>> vec2 = { v2, v3 };

	Matrix Q(vec1);
	Matrix R(vec2);
	//S.print();
	//R.print();
	Matrix A = (Q * R);

	A.print();
	A = A.transpose();
	A.print();
	A.transpose().print();
	A.print();


	//(S*(R * S * R)).print();

	//S.getCol(0).print();


}