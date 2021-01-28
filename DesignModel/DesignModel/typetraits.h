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


class TypeInfo
{
public:
	TypeInfo();
	TypeInfo(const std::type_info&);
	TypeInfo(const TypeInfo&);
	TypeInfo& operator=(const TypeInfo&);
	bool before(const TypeInfo&) const;
	const char* name() const;

private:
	const std::type_info* pInfo_;
};

bool operator==(const TypeInfo&, const TypeInfo&);
bool operator!=(const TypeInfo&, const TypeInfo&);
bool operator<(const TypeInfo&, const TypeInfo&);
bool operator<=(const TypeInfo&, const TypeInfo&);
bool operator>(const TypeInfo&, const TypeInfo&);
bool operator>=(const TypeInfo&, const TypeInfo&);


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