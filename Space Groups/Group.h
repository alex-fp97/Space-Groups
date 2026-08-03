#pragma once
#include <iostream>
#include <functional>
#include <vector>

template <typename T>
class Group {

	std::vector<T> gp_elements;
	T identity;
	int order = 0;

public:
	
	Group(const std::vector<T>& elements) : gp_elements(elements), order(static_cast<int>(gp_elements.size())) { setIdentity(); }
	~Group() {}

	T getIdentity()
	{
		return identity;
	}

	void setIdentity()
	{
		T e = gp_elements[0];
		for (int i = 0; i < order; i++)
		{
			e = e * e;
		}
		identity = e;
	}

	std::vector<T> getElements()
	{
		return gp_elements;
	}

	/*/T operator* (T a, T b) {
		return group_operation{}(a, b);
	}*/


	//T getIdentity() { return identity; }

	//T findIdentity();

	//T operator*(const T &elem)
		
};
