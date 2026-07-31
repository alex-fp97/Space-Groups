#include <iostream>
#include "Matrix.h"
#include "Vector.h"

int main() {

	Vector v1(std::vector<double>{ 3, 2, 4 });
	Vector v2(std::vector<double>{ 1, 4, 5 });
	Vector v3(std::vector<double>{ 1 });


	Matrix m({ v1, v3 });
	Matrix k({ v2, v1 });
	k = k.transpose();

	std::cout << "oo";

	m.print(); std::cout << std::endl;
	//k.print(); std::cout << std::endl;

}