#pragma once

#include "common.h"

template<typename T> class my_stack;

template<typename T>
class list_node
{
public:
	T value;
	list_node* next;

	list_node(T const &v, list_node* n):
		value(v), next(n)
	{}

	friend class my_stack<T>;
};


template<typename T=int>
class my_stack
{

};