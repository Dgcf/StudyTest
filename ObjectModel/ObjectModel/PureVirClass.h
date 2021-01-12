#pragma once
#include "common.h"


class PureVirClass
{
public:
	virtual void func1() = 0;
	virtual void func2() = 0;
};


class SubPureVir1 : public PureVirClass
{
public:
	void func1()
	{
		cout << "SubPureVir1::func1" << endl;
	}

	void func2()
	{
		cout << "SubPureVir1::func2" << endl;
	}
};


class SubPureVir2 : public PureVirClass
{
public:
	void func1()
	{
		cout << "SubPureVir2::func1" << endl;
	}

	void func2()
	{
		cout << "SubPureVir2::func2" << endl;
	}
};


class SubPureVir3 : public PureVirClass
{
	void func1()
	{
		cout << "SubPureVir3::func1" << endl;
	}

	void func2()
	{
		cout << "SubPureVir3::func2" << endl;
	}

	int operator++(int)
	{
		int y = x;
		x += 1;
		return y;
	}

private:
	int x;
};

PureVirClass* GetObj();
void test_pure_class();