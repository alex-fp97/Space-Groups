#pragma once
#include <iostream>
#include <unordered_set>
#include <functional>
#include <random>

template <typename T>
class Group {

	std::vector<T> group_elements;
	T identity;
	T(*group_operation)(T, T);
	T op;

public:
	

	Group(std::vector<T> elements, T (*operation)(T, T)) : group_elements(elements), group_operation(operation) {}
	~Group() {}

	T operator* (T a, T b) {
		return group_operation{}(a, b);
	}


	//T getIdentity() { return identity; }

	//T findIdentity();

	//T operator*(const T &elem)
		
};
