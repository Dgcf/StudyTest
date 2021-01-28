#pragma once


#include "typelist.h"


template<typename T>
class AFUint
{
public:
	virtual T* DoCreate(Type2Type<T>) = 0;
	virtual ~AFUint() {}
};


//template<class TList, template<typename> class Unit=AFUint>
//class AbstractFactory : public GenScatterHierarchy<TList, Unit>
//{
//public:
//	typedef TList ProductList;
//	template<class T> T* Create()
//	{
//		Unit<T>& unit = *this;
//		return this->DoCreate(Type2Type<T>());
//	}
//};
