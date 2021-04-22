#pragma once


#include "typelist.h"


template<typename T>
class AFUint
{
public:
	virtual T* DoCreate(Type2Type<T>) { return nullptr; }
	virtual ~AFUint() {}
};


template<class TList, template<typename> class Unit=AFUint>
class AbstractFactory : public tl::GenScatterHierarchy<TList, Unit>
{
public:
	typedef TList ProductList;
	template<class T> T* Create()
	{
		Unit<T>& unit = *this;
		return unit.DoCreate(Type2Type<T>());
	}
};

class Solider {
public:
	void PrintSolider()
	{
		cout << "PrintSolider" << endl;
	}
};

class Monster {
public:
	void PrintMonster()
	{
		cout << "PrintMonster" << endl;
	}
};

class SuperMonster {
public:
	void PrintSuperMonster()
	{
		cout << "PrintSuperMonster" << endl;
	}
};

typedef AbstractFactory<
	TYPELIST_3(Solider, Monster, SuperMonster)
> AbstractEnemyFactory;




