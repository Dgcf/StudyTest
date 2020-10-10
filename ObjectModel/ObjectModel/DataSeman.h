#pragma once
#include "common.h"


class X
{
};

class Y : public virtual X
{

};

class Z : public virtual X
{

};

class A : public Y, public Z
{

};

inline void Test_data_0()
{
	cout << "sizeof X: " << sizeof(X) << endl;
	cout << "sizeof Y: " << sizeof(Y) << endl;
	cout << "sizeof Z: " << sizeof(Z) << endl;
	cout << "sizeof A: " << sizeof(A) << endl;
}

class C
{
public:
	int a;
	int b;
	int c;

	C() :a(12), b(13), c(14) {}
};

inline void C_Test()
{
	C c;
	cout << "aa" << endl;
}

class PointData
{
public:
	virtual ~PointData() {}

public:
	float x, y, z;
};

class PointData1
{
public:
	float x, y, z;
};

inline void Test_Data_Point()
{
	printf("%p\n", &PointData::x);
	printf("%p\n", &PointData::y);
	printf("%p\n", &PointData::z);

	cout << &PointData::x << endl;
	cout << &PointData::y << endl;
	cout << &PointData::z << endl;

	printf("%p\n", &PointData1::x);
	printf("%p\n", &PointData1::y);
	printf("%p\n", &PointData1::z);

	cout << &PointData1::x << endl;
	cout << &PointData1::y << endl;
	cout << &PointData1::z << endl;
}
