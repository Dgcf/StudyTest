#pragma once
#include "common.h"


template<typename T, typename Y>
class TypeList
{
	typedef T Head;
	typedef Y Tail; 
};

template<typename Head, typename Tail>
class TypeAt<0, TypeList<Head, Tail>>
{
	typedef Head Result;
};

template<unsigned int i, typename Head, typename ...Tail>
class TypeAt
{
public:
	typedef typename TypeAt<i-1, ...Tail>::Result Result;
};

template<typename T, typename ...Args>
class CLdpMsgWriterHelper
{
public:
	CLdpMsgWriterHelper(int* p)
	{
		std::bool_constant<std::is_void<T>::value> v;
		cout << FixedLen(v) << endl;
	}

protected:
	int FixedLen(std::false_type)
	{
		cout << "false type" << endl;
		return sizeof(T);
	}

	int FixedLen(std::true_type)
	{
		cout << "true type" << endl;
		return 0;
	}
};

