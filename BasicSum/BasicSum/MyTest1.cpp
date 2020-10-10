#include "MyTest1.h"

void test_static_var0()
{
	//cout << ++g_stI << endl;
	cout << ++g_iTest << endl;
	//cout << g_ciTest0 << endl;
}

void test_MyTest1_0()
{
	MyTest1 t0;
	t0.print();

	const MyTest1 t1;
	t1.print();

	t0.test_Null();
}