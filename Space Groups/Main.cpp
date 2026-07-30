#include <iostream>
#include <functional>
#include "Group.h"
#include <vector>
#include "Matrix.h"
#include "Vector.h"

int main() {

	std::vector<double> comps = {3, 2, 4};

	Vector v1(comps);
	Vector v2(comps);

	//v1.print();
	//v2.print();

	std::vector<Vector> elems = { v1, v2 };

	Matrix test(elems);
	Matrix test1(elems);

	Matrix add(test + test1);

	//test.print();
	//test1.print();
	add.print();
	add.getRow(0).print(); std::cout<<std::endl;
	add.getCol(0).print();
	add.print();
}