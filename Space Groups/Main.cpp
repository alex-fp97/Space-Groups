#include <iostream>
#include "Matrix.h"
#include "Vector.h"
int main() {

	Vector v1({ 0, 1 });
	Vector v2({ -1, 0 });

	Vector v3({ 0, -1 });
	Vector v4({ 1, 0 });

	Matrix S_Inverse({ v3, v4 });

	Matrix S({ v1, v2 });
	Matrix R({ v2, v1 });

	S.print();
	R.print();

	(S*(R * S * R)).print();

	S.getRow(0).print();
}