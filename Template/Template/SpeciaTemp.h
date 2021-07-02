#pragma once
#include "common.h"

template<typename T>
inline void print_special(T& t)
{
	cout << "common: " << endl;
}

template<>
inline void print_special(const char*& s)
{
	cout << "special: " << endl;
}

/// <summary>
/// 两个问题
/// 1.传入char*也走第一个模板
/// 2.特例化的参数改成const char*编译报错
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name=""></param>

template<typename T>
inline void fobj(T)
{
	cout << "Enter in fobj" << endl;
}

template<typename T>
inline void fref(const T&, const T&)
{
	cout << "Enter in fref: " << endl;
}