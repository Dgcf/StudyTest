#pragma once


class NullType;
struct EmptyType {};


namespace tl
{
	template<typename T, typename U>
	struct TypeList
	{
		typedef T Head;
		typedef U Tail;
	};


}

#define TYPELIST_1(T1) tl::Typelist<T1, NullType>
#define TYPELIST_2(T1, T2) tl::Typelist<T1, TYPELIST_1(T2)>
#define TYPELIST_3(T1, T2, T3) tl::Typelist<T1, TYPELIST_1(T2, T3)>
#define TYPELIST_4(T1, T2, T3, T4) tl::Typelist<T1, TYPELIST_3(T1, T2, T3)>