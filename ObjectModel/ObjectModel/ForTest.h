#pragma once
#include "Derived.h"


void test_Derived();

void test_memptr();

class ABC
{
public:
	ABC(int a, char b)
	{
		cout << "a: " << a << " b: " << b << endl;
	}
};

void test_Class();