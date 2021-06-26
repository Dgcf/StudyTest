#pragma once
#include "common.h"

struct T
{
	enum { int_t, float_t } type;

	template <typename Integer,
		std::enable_if_t<std::is_integral<Integer>::value, bool> = true
	>
		T(Integer) : type(int_t) {
		cout << "Integer" << endl;
	}

	template <typename Floating,
		std::enable_if_t<std::is_floating_point<Floating>::value, bool> = true
	>
		T(Floating) : type(float_t) {
		cout << "Floating" << endl;
	} // OK
};


template
<
	typename _Ty,
	typename ...Args
>
struct T1
{
	template <typename _Py, std::enable_if_t<std::is_integral<_Py>::value, bool> = true >
	T1(_Py)
	{
		cout << "Integer" << endl;
	}

	template <typename _Py, std::enable_if_t<std::is_floating_point<_Py>::value, bool> = true>
	T1(_Py)
	{
		cout << "Floating" << endl;
	}

	template <size_t i>
	struct arg
	{
		typedef typename std::tuple_element<i, std::tuple<Args...>>::type type;
	};

	template <size_t i>
	typename arg<i>::type GetTest()
	{
		cout << typeid(typename arg<i>::type).name() << " size is: " << sizeof(typename arg<i>::type) << endl;
		return "hello";
	}

	/*template <size_t i, std::enable_if<std::is_same<_Ty, int>, bool> = true>
	typename arg<i>::type* GetTest()
	{
		cout << typeid(typename arg<i>::type).name() << " size is: " << sizeof(typename arg<i>::type) << endl;
		return 123;
	}*/
};