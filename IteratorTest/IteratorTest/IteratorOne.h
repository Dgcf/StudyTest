#pragma once

#include "common.h"

void test_one();
void test_two();

void test_three(string s, int n, ...);

class ABC
{
public:
	ABC();
	void print()
	{
		Init();
		cout << s1 << endl;
	}

	static void Init()
	{
		s1 = "big";
	}
private:
	static string s1;
};