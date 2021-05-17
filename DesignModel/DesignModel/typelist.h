#pragma once
#include "common.h"

class NullType;
struct EmptyType {};

// 整数做为类型
template<int v>
struct Int2Type
{
	enum
	{
		value = v
	};
};

template<typename T>
struct Type2Type
{
	typedef T OriginalType;
};

template<const char* s>
struct Str2Type {};

// 只为了携带型别信息
template<typename T, typename U>
struct TypeList
{
	typedef T Head;
	typedef U Tail;
};


#define TYPELIST_1(T1) TypeList<T1, NullType>
#define TYPELIST_2(T1, T2) TypeList<T1, TYPELIST_1(T2)>
#define TYPELIST_3(T1, T2, T3) TypeList<T1, TYPELIST_2(T2, T3)>
#define TYPELIST_4(T1, T2, T3, T4) TypeList<T1, TYPELIST_3(T2, T3, T4)>


namespace tl
{
	

	// 计算typelist的长度
	template<class TList> struct Length;

	template<>
	struct Length<NullType>
	{
		enum { value = 0 };
	};

	template<class T, class U>
	struct Length<TypeList<T, U>>
	{
		enum
		{
			value = 1 + Length<U>::value
		};
	};


	// 索引式访问
	template<class TList, unsigned int index> struct TypeAt;

	template<class Head, class Tail>
	struct TypeAt<TypeList<Head, Tail>, 0>
	{
		typedef Head Result;
	};

	template<class Head, class Tail, unsigned int i>
	struct TypeAt<TypeList<Head, Tail>, i>
	{
		typedef typename TypeAt<Tail, i - 1>::Result Result;
	};


	// 查找typelist
	template<class TList, class T> struct IndexOf;

	template<class T>
	struct IndexOf<NullType, T>
	{
		enum
		{
			value = -1
		};
	};

	template<class Tail, class T>
	struct IndexOf<TypeList<T, Tail>, T>
	{
		enum
		{
			value = 0
		};
	};

	template<class Head, class Tail, class T>
	struct IndexOf<TypeList<Head, Tail>, T>
	{
	private:
		enum { temp = IndexOf<Tail, T>::value };

	public:
		enum
		{
			value = temp == -1 ? -1 : 1 + temp
		};
	};

	template<class TList, class T> struct Append;

	template<>
	struct Append<NullType, NullType>
	{
		typedef NullType Result;
	};

	template<class T>
	struct Append<NullType, T>
	{
		typedef TypeList<T, NullType> Result;
	};

	template<class Head, class Tail>
	struct Append<NullType, TypeList<Head, Tail>>
	{
		typedef TypeList<Head, Tail> Result;
	};

	template<class Head, class Tail, class T>
	struct Append<TypeList<Head, Tail>, T>
	{
		typedef TypeList<Head, typename Append<Tail, T>::Result>
			Result;
	};


	// 移除元素
	template<class TList, class T> struct Erase;
	template<class T>
	struct Erase<NullType, T>
	{
		typedef NullType Result;
	};

	template<class T, class Tail>
	struct Erase <TypeList<T, Tail>, T>
	{
		typedef Tail Result;
	};

	template<class Head, class Tail, class T>
	struct Erase<TypeList<Head, Tail>, T>
	{
		typedef TypeList<Head, typename Erase<Tail, T>::Result> Result;
	};


	// 移除重复元素
	template<class TList> struct NoDuplicates;
	template<> struct NoDuplicates<NullType>
	{
		typedef NullType Result;
	};

	template<class Head, class Tail>
	struct NoDuplicates<TypeList<Head, Tail>>
	{
	private:
		typedef typename NoDuplicates<Tail>::Result L1;
		typedef typename Erase<L1, Head>::Result L2;

	public:
		typedef TypeList<Head, L2> Result;
	};

	// 取代Typelist中的某个元素
	template<class TList, class T, class U> struct Replace;

	template<class T, class U>
	struct Replace<NullType, T, U>
	{
		typedef NullType Result;
	};

	template<class T, class Tail, class U>
	struct Replace<TypeList<T, Tail>, T, U>
	{
		typedef TypeList<U, Tail> Result;
	};

	template<class Head, class Tail, class T, class U>
	struct Replace<TypeList<Head, Tail>, T, U>
	{
		typedef TypeList<Head, typename Replace<Tail, T, U>::Result> Result;
	};


	// 运用Typelists自动产生Classes
	template<class TList, template<typename>class Unit>
	class GenScatterHierarchy;

	template<class T1, class T2, template<typename> class Unit>
	class GenScatterHierarchy<TYPELIST_2(T1, T2), Unit>
		: public GenScatterHierarchy<T1, Unit>
		, public GenScatterHierarchy<T2, Unit>
	{

	};

	template<class AtomicType, template<class> class Unit>
	class GenScatterHierarchy : public Unit<AtomicType>
	{

	};

	template<template<class>class Unit>
	class GenScatterHierarchy<NullType, Unit>
	{

	};
}

template<class T>
struct Holder
{
	T value_;
};

//typedef tl::GenScatterHierarchy<TYPELIST_3(int, string, Widget), Holder> WidgetInfo;


