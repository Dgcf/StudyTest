#pragma once
#include "common.h"

template<typename T, void (*f)(T& v)>
inline void foreach(T a[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		f(a[i]);
	}
}

template<typename T>
inline void inc(T& v)
{
	++v;
}

template<typename T>
inline void dec(T& v) { --v; }

template<typename T> inline void print(T& v) { cout << ' ' << v; }

// 以指针作为模板参数
template<int* p>
struct wrapper
{
	int get() { return *p; }
	void set(int v) { *p = v; }
};

// 以引用作为模板参数
template<int &p>
struct wrapper2
{
	int get() { return p; }
	void set(int v) { p = v; }
};


// 成员函数指针


// 模板型模板参数
template
<
	typename T,
	template
	<
		typename TT0,
		typename TT1
	>
	class NoTypeA
>
class NoTypeB
{

};

template
<
	typename T,
	template<typename TT> class Func
>
inline void foreach1(T ar[], size_t size)
{
	Func<T> f;
	for (size_t i = 0; i < size; i++)
	{
		f(ar[i]);
	}
}

template<typename T>
struct inc1 {
	void operator()(T& v) const { ++v; }
};

template<typename T>
struct print1 {
	void operator()(T& v)const { std::cout << ' ' << v; }
};

template<size_t i>
inline void print2()
{
	print2<i - 1>();
	cout << i << endl;
}

template<>
inline void print2<1>()
{
	cout << 1 << std::endl;
}



