#pragma once
#include "common.h"


template<typename T>
struct NoChecking
{
	static void Check(T*) {}
};

template<typename T>
struct EnforceNotNull
{
	class NullPointerException: public std::exception{...};
	static void Check(T* ptr)
	{
		if (!ptr)
		{
			throw NullPointException();
		}
	}
};


template<typename T>
struct EnsureNotNull
{
	static void Check(T*& ptr)
	{
		if (!ptr)
			ptr = GetDefaultValue();
	}
};


template
<
	typename T,
	template <typename> class CheckingPolicy,
	template<typename> class ThreadingModel
>
class SmartPtr: public CheckingPolicy<T>, public ThreadingModel<SmartPtr>
{

};