#pragma once
#include "common.h"

template<typename T>
int compare(const T& parm1, const T& parm2)
{
	cout << parm1 << " " << parm2 << endl;
	return 0;
}

int (*pf1)(const int&, const int&) = compare;

template<typename T>
void f3(T&& val)
{
	T t = val;
}

// std::move源码
template<typename T>
typename remove_reference<T>::type&& tmove(T&& t)	// 引用折叠，此参数可以和任何类型的实参匹配
{
	return static_cast<typename remove_reference<T>::type&&>(t);
}

void ft1(int v1, int& v2)
{
	cout << v1 << " " << ++v2 << endl;
}

template<typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
	f(t2, t1);
}

template<typename T>
string debug_rep(const T &t)
{
	ostringstream ret;
	ret << *t;
	return ret.str();
}

template<typename T>
string debug_rep(T* p)
{
	ostringstream ret;
	ret << "pointer:" << p;
	/*if (p)
	{
		ret << " " << debug_rep(p);
	}
	else
	{
		ret << " null pointer";
	}*/
	return ret.str();
}

string debug_rep(string &p)
{
	cout << "string debug_rep" << endl;
	cout << p << endl;
	return p;
}

template<typename T>
ostream& print(ostream& os, const T& t)
{
	return os << t;
}

template<typename T, typename... Args>
ostream& print(ostream& os, const T& t, const Args&... rest)
{
	os << t << ", ";
	return print(os, rest...);
}



//template<typename T>
//void print0(T t)
//{
//	string s = c;
//	cout << s << endl;
//}
