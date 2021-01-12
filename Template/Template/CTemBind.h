#pragma once

#include "common.h"

class CTemBind1
{
public:

	void print_two(const int& a)
	{
		cout << "print_two: " << a << endl;
	}

	template<typename _Tp>
	void print_one(const _Tp& t, std::function<void(const _Tp&)> f)
	{
		cout << "print_one" << endl;
		f(t);
	}
};

class CTemBind2
{
public:
	void test()
	{
		int a = 12;
		std::function<void(const int&) > f = std::bind(&CTemBind1::print_two, &bind1_, std::placeholders::_1);
		bind1_.print_one(a, f);
	}
private:
	CTemBind1 bind1_;
};

static inline int const_test(char* const s)
{
	cout << s << endl;
	return 0;
}

