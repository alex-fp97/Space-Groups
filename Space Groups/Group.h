#pragma once
#include <iostream>
#include <functional>
#include <vector>

template <typename T>
class Group {

	std::vector<T> gp_elements;
	T identity;
	T(*gp_operation)(const T&);

public:
	

	Group(const std::vector<T> &elements, std::function<T(const T&)> func);
	~Group();

	/*/T operator* (T a, T b) {
		return group_operation{}(a, b);
	}*/


	//T getIdentity() { return identity; }

	//T findIdentity();

	//T operator*(const T &elem)
		
};
