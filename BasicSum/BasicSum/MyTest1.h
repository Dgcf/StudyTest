#pragma once
#include "common.h"
//#include "Test.h"
extern int g_iTest;
extern const int g_ciTest;

void test_static_var0();

class MyTest1
{
public:
	MyTest1():x("good"), iTest0(1), iTest1(nullptr)
	{

	}

	void print() const
	{
		cout << x << endl;
		cout << ++iTest0 << endl;
	}

	void print()
	{
		x += " morning";
		cout << x << endl;
		//cout << ++iTest0 << endl;
	}

	void test_Null()
	{
		cout << sizeof(nullTest0) << endl;
	}

private:
	string x;
	mutable int iTest0;
	int* iTest1;
	nullptr_t nullTest0;
};

void test_MyTest1_0();

int testparams(int count, ...);


template<typename ... Args> 
void g(Args ... args) 
{
	cout << sizeof...(Args) << endl;
	cout << sizeof...(args) << endl;
}

template<typename T, typename... Args>
ostream& print(ostream& os, const T& t, const Args&... rest)//��չģ�������Args����ģʽconst Args&Ӧ�õ�ģ�����Args
{                      //�е�ÿ��Ԫ�أ���ˣ���ģʽ����չ�����һ�����ŷָ�������������͵��б�ÿ�����Ͷ���const type&
	os << t << ", ";
	return print(os, rest...);    // ��չrest��Ϊprint��������ʵ���б�
}

class ABC
{
public:
	ABC() {}
	ABC(ABC&&) {}
};

class Ptr
{
public:
	Ptr(std::unique_ptr<ABC>& p)
	:p_(std::move(p))
	{}

private:
	std::unique_ptr<ABC> p_;
};
