#include <iostream>
#include <functional>
#include "Group.h"
#include <vector>
#include "Vector.h"

int mod6(int a, int b) {
	return (a + b) % 6;
}


int main() {

	std::vector<double> comps = { 3, 2, 4 };

	Vector v1(3);
	Vector v2(3);

	v1.setVectorComponents(comps);
	v2.setVectorComponents(comps);

	std::vector<Vector> elems = { v1, v2 };

	Group<Vector> test(elems, Vector(*Vector.operator*)(Vector, Vector));


	Vector v3 = v1 + v2;
	v1.print();
	v2.print();
	v3.print();

}