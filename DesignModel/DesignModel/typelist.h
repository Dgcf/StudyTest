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

template<int v>
struct Int2Type
{
	enum
	{
		value = v;
	};
};


template<typename T>
struct Type2Type
{
	typedef T OriginalType;
};


#define TYPELIST_1(T1) tl::Typelist<T1, NullType>
#define TYPELIST_2(T1, T2) tl::Typelist<T1, TYPELIST_1(T2)>
#define TYPELIST_3(T1, T2, T3) tl::Typelist<T1, TYPELIST_2(T2, T3)>
#define TYPELIST_4(T1, T2, T3, T4) tl::Typelist<T1, TYPELIST_3(T2, T3, T4)>

template<class TList> struct Length;

template<> 
struct Length<NullType>
{
	enum { value = 0 };
};

template<class T, class U>
struct Length<tl::TypeList<T, U>>
{
	enum 
	{
		value = 1 + Length<U>::value
	};
};

template<class TList, unsigned int index> struct TypeAt;

template<class Head, class Tail>
struct TypeAt<tl::TypeList<Head, Tail>, 0>
{
	typedef Head Result;
};

template<class Head, class Tail, unsigned int i>
struct TypeAt<tl::TypeList<Head, Tail>, i>
{
	typedef typename TypeAt<Tail, i - 1>::Result Result;
};


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
struct IndexOf<tl::TypeList<T, Tail>, T>
{
	enum 
	{
		value = 0
	};
};

template<class Head, class Tail, class T>
struct IndexOf<tl::TypeList<Head, Tail>, T>
{
private:
	enum { temp = IndexOf<Tail, T>::value };

public:
	enum
	{
		value = temp == -1 ? -1 : 1 + temp;
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
	typedef TYPELIST_1(T) Result;
};

template<class Head, class Tail>
struct Append<NullType, tl::TypeList<Head, Tail>>
{
	typedef tl::TypeList<Head, Tail> Result;
};

template<class Head, class Tail, class T>
struct Append<tl::TypeList<Head, Tail>, T>
{
	typedef tl::TypeList<Head, typename Append<Tail, T>::Result>
		Result;
};