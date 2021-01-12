#pragma once
#include "common.h"

struct MyStruct
{
	int a;
	char b[32];
};

class CopySemantic
{
public:
	CopySemantic():sc_("hello")
	{
		memset(&st, 0, sizeof(st));
		db_ = 23.45;
	}

private:
	MyStruct st;
	double db_;
	string sc_;
};

static void Test_CopySemantic()
{
	CopySemantic c1, c2;
	memcpy(&c2, &c1, sizeof(c2));
	cout << "End of Test_CopySemantic" << endl;
}



