#include <iostream>
#include "matr.h"
#include "Group.h"
int main() {

	std::vector<double> v1 = { 0, -1 };
	std::vector<double> v2 = { 1, 0 };
	std::vector<double> v3 = { -1, 0 };
	std::vector<double> v4 = { 0, 1 };

	std::vector<std::vector<double>> vec1 = { v1, v2 };
	std::vector<std::vector<double>> vec2 = { v3, v4 };

	Matrix S(vec1);
	Matrix R(vec2);
	//S.print();
	//R.print();
	Matrix I = S * S * S * S;

	//I.print();
	
	std::vector<Matrix> e = { S, (S * S), (S * S * S), R };

	Group<Matrix> D(e);

	D.getIdentity().print();

	std::vector<Matrix> D_elems = D.getElements();

	D_elems[0].print();



}