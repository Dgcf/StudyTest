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
	template<typename U>
	struct PointerTraits
	{
		enum { result = false };
		typedef NullType PointeeType;
	};

	template<typename U>
	struct PointerTraits<U*>
	{
		enum { result = true };
		typedef U PointeeType;
	};

public:
	enum { isPointer = PointerTraits<T>::result };
	typedef typename PointerTraits<T>::PointeeType PtrType;

// ָ�����Ա��ָ��
private:
	template<typename U>
	struct PToMTraits
	{
		enum { result = false };
	};

	template<typename U, typename V>
	struct PToMTraits<U V::*>
	{
		enum { result = true };
	};

public:
	enum { isMemPtr = PToMTraits<T>::result };

// ȥ��const����
private:
	template<class U>
	struct UnConst
	{
		typedef U Result;
	};

	template<class U>
	struct UnConst<const U>
	{
		typedef U Result;
	};

public:
	typedef typename UnConst<T>::Result NonConstType;
};