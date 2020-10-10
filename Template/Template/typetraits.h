#pragma once

#include "common.h"


template<typename T, typename E>
struct check
{
	check() { cout << "typename T, typename E" << endl; }
};

template<typename T>
struct check<T, typename std::enable_if<sizeof(T)==1>::type>
{
	check() { cout << "pi" << endl; }
	int x = 10;
};

struct A
{
	bool value;
};

void test0();

template<typename T>
constexpr bool is_me = false;

void test_enable_if();

template<typename T=void>
class Z
{
public:
	void judge()
	{
		if (is_void<T>())
		{
			cout << "T is void" << endl;
		}
		else
		{
			cout << "T is not void" << endl;
		}
	}
};

struct ZC
{
	int x;
};

inline void test_is_void()
{
	Z<> z1;
	z1.judge();
	Z<ZC> z2;
	z2.judge();
	std::is_void<void>();
}
