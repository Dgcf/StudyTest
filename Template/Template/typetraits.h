#pragma once

#include "common.h"


namespace my_traits
{
	template<typename T1, typename T2>
	struct is_same
	{
		enum { value=0	};
	};

	template<typename T>
	struct is_same<T, T>
	{
		enum { value = 1 };
	};

	template
	<
		bool C0,
		typename C1,
		typename C2
	>
	struct enable_if 
	{
		typedef C1 type;
	};

	template<typename C1, typename C2>
	struct enable_if<false, C1, C2>
	{
		typedef C2 type;
	};

}

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

/*****************************
* std::conjunction_v
*****************************/
//template<class, class>
//constexpr int abc = 11;

template<typename _Ty>
constexpr int abc = 10;

template<typename T, typename... Ts>
std::enable_if_t<std::conjunction_v<std::is_same<T, Ts>...>>
func(T, Ts...) {
	std::cout << "all types in pack are T\n";
}

// otherwise
template<typename T, typename... Ts>
std::enable_if_t<!std::conjunction_v<std::is_same<T, Ts>...>>
func(T, Ts...) {
	std::cout << "not all types in pack are T\n";
}

/*************************
* std::addressofµÄÓÃ·¨
**************************/
template<class T>
struct Ptr {
	T* pad; // add pad to show difference between 'this' and 'data'
	T* data;
	Ptr(T* arg) : pad(nullptr), data(arg)
	{
		std::cout << "Ctor this = " << this << std::endl;
	}

	~Ptr() { delete data; }
	T** operator&() 
	{ 
		return &data; 
	}
};

template<class T>
inline void f(Ptr<T>* p)
{
	std::cout << "Ptr overload called with p = " << p << '\n';
}

inline void f(int** p)
{
	std::cout << "int** overload called with p = " << p << '\n';
}
