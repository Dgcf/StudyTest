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
/// ��������
/// 1.����char*Ҳ�ߵ�һ��ģ��
/// 2.�������Ĳ����ĳ�const char*���뱨��
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