#include "typetraits.h"

void test0()
{
	check<char, void> c1;
	check<int, void> c2;
}

void test_enable_if()
{
	int* n = new int(10);
	if (is_me<int*>)
	{
		cout << "is my pointer" << endl;
	}
	else
	{
		cout << "is not pointer" << endl;
	}
}
