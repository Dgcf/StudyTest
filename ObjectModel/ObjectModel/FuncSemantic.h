#pragma once

#include "common.h"

class FuncSemantic
{
public:
	static void StaFunTest()
	{
		cout << "FuncSemantic::StaFunTest" << endl;
	}
};

inline void FuncTest0()
{
	((FuncSemantic*)0)->StaFunTest();
}

//class Base1
//{
//public:
//	Base1();
//	virtual ~Base1();
//	virtual 
//};

class F1
{
	//static int x = 10;
public:
	void F1_test_0() {}
	void F1_test_1() {};
	int i0;
	void F1_test_2() {};
};

inline void Test_Fun()
{
	//F1 f1;
	cout << &F1::F1_test_0 << endl;
	cout << &F1::F1_test_1 << endl;
	cout << &F1::i0 << endl;
	cout << &F1::F1_test_2 << endl;
	// cout << F1::x << endl;
	// cout << &(f1.F1_test_0) << endl;
}

