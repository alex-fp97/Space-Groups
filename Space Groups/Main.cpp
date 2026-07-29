#include <iostream>
#include <functional>
#include "Group.h"
#include <vector>
#include "Vector.h"

int main() {

	std::vector<double> comps = {3, 2, 4};

	Vector v1(comps);
	Vector v2(comps);

	v1.print();
	v2.print();

	//std::vector<Vector> elems = { v1, v2 };

	//Group<Vector> test(elems, Vector(*Vector.operator*)(Vector, Vector));


	Vector v3(3);
	v3 = (v1 + v2);
	v1.print();
	v2.print();
	v3.print();

	std::cout << v1 * v2;

}