#pragma once
#include <typeinfo>
#include "typelist.h"
using namespace std;

template<bool flag, typename T, typename U>
struct Select
{
	typedef T Result;
};

template<typename T, typename U>
struct Select<false, T, U>
{
	typedef U Result;
};


template<typename T>
class TypeTraits
{
private:
	template<class U>struct UnConst
	{
		typedef U Result;
	};

	template<class U>struct UnConst<const U>
	{
		typedef U Result;
	};

public:
	typedef UnConst<T>::Result NonConstType;
};