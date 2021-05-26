#pragma once
#include "common.h"

class NullType;
struct EmptyType {};

// ������Ϊ����
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


// ֻΪ��Я���ͱ���Ϣ
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
	// ����typelist�ĳ���
	template<class TList> struct TL_Length;

	template<>
	struct TL_Length<NullType>
	{
		enum { value = 0 };
	};

	template<class T, class U>
	struct TL_Length<TypeList<T, U>>
	{
		enum
		{
			value = 1 + TL_Length<U>::value
		};
	};


	// ����ʽ����
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

	template <class TList, unsigned int index,
		typename DefaultType = NullType>
		struct TypeAtNonStrict
	{
		typedef DefaultType Result;
	};

	template <typename Head, typename Tail, typename DefaultType>
	struct TypeAtNonStrict<TypeList<Head, Tail>, 0, DefaultType>
	{
		typedef Head Result;
	};

	template <class Head, class Tail, unsigned int i, typename DefaultType>
	struct TypeAtNonStrict<TypeList<Head, Tail>, i, DefaultType>
	{
		typedef typename
			TypeAtNonStrict<Tail, i - 1, DefaultType>::Result Result;
	};


	// ����typelist
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


	// �Ƴ�Ԫ��
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

/***************************************************************************************************
�Ƴ�Ԫ�صĲ��裬��tl::Append<TYPELIST_4(int, float, double, char), string>::ResultΪ����
1.tl::Erase<TypeList<int, TypeList<float, TypeList<double, NullType>>>, float>::Result
  ResultΪTypeList<int, typename Erase<TypeList<float, TypeList<double, NullType>>,float>::Result>
2.�ݹ���һ����Erase��Erase<TypeList<float, TypeList<double, NullType>>,float>::Result
  ResultΪTypeList<double, NullType>
***************************************************************************************************/


	// �Ƴ��ظ�Ԫ��
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

/**************************************************************************************************
�Ƴ��ظ�Ԫ�ز��裬��NoDuplicates<TYPELIST_4(int, float, double, float)>::ResultΪ��
1.Result:TypeList<int, L2>
2.L2:Erase<L1, int>::Result;
3.L2:Erase<NoDuplicates<TypeList<float, TypeList<double, TypeList<float, NullType>>>>::Result, int>::Result
4.�ֽ�NoDuplicates<TypeList<float, TypeList<double, TypeList<float, NullType>>>>::Result
5.4�е�ResultΪTypeList<float, Erase<NoDuplicates<TypeList<double, TypeList<float, NullType>>>::Result, float>::Result>
6.�ֽ�5�е�NoDuplicates<TypeList<double, TypeList<float, NullType>>>::Result
7.6�е�ResultΪTypeList<double, Erase<NoDuplicates<TypeList<float, NullType>>::Result, double>::Result>
8.�ֽ�7�е�NoDuplicates<TypeList<float, NullType>>::Result
9.8�е�ResultΪTypeList<float, Erase<NoDuplicates<NullType>::Result, float>::Result>
10.Erase<NoDuplicates<NullType>::ResultΪ��TypeList<float, NullType>
��ʼ���룺
9. TypeList<float, TypeList<float, NullType>>
7. TypeList<double, Erase<TypeList<float, TypeList<float, NullType>>, double>::Result>
...
**************************************************************************************************/

	// ȡ��Typelist�е�ĳ��Ԫ��
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


	// ����Typelists�Զ�����Classes
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


