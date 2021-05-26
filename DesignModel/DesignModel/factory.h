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


class Shape
{
public:
	virtual void Draw() const = 0;
	virtual void Rotate(double angle) = 0;
	virtual void Zoom(double zoomFactor) = 0;
};

class Drawing
{

};

template
<
	typename AbstractProduct,
	typename IdentifierType,
	typename ProductCreator
>
class Factory
{
public:
	bool Register(const IdentifierType& id, ProductCreator creator)
	{
		return associations_.insert(AssocMap::vlaue_type(id, creator)).second;
	}

	bool UnRegister(const IdentifierType& id)
	{
		return associations_.erase(id) == 1;
	}

	AbstractProduct* CreateObject(const IdentifierType& id)
	{
		typename AssocMap::const_iterator it = associations_.find(id);
		if (it == associations_.end())
		{
			throw runtime_error("")
		}
		return (it->second)();
	}

private:
	typedef std::map<IdentifierType, AbstractProduct> AssocMap;
	AssocMap associations_;
};


class ShapeFactory
{
public:
	typedef Shape* (*CreateShapeCallback)();

private:
	typedef std::map<int, CreateShapeCallback> CallbackMap;

public:
	bool RegisterShape(int ShapeId, CreateShapeCallback CreateFn)
	{
		return callbacks_.insert(CallbackMap::value_type(ShapeId, CreateFn)).second;
	}

	bool UnRegisterShape(int ShapeId)
	{
		return callbacks_.erase(ShapeId) == 1;
	}

	Shape* CreateShape(int ShapeId)
	{
		CallbackMap::const_iterator it = callbacks_.find(ShapeId);
		if (it == callbacks_.end())
		{
			throw runtime_error("Unknown Shape ID");
		}
		return (it->second)();
	}

private:
	CallbackMap callbacks_;
};


