#pragma once

#include "TypeInfo.h"


class Shape
{
public:
	virtual void Draw() const = 0;
	virtual void Rotate(double angle) = 0;
	virtual void Zoom(double zoomFactor) = 0;
	virtual Shape* Clone() const = 0;
};

class Line
{
public:
	virtual Line* Clone() const
	{
		return new Line(*this);
	}
};

class Drawing
{

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


template<typename IdentifierType, typename ProductType>
class DefaultFactoryError
{
public:
	class Exception : public std::exception
	{
	public:
		Exception(const IdentifierType& unknownId)
			: unknownId_(unknownId)
		{
		}

		virtual const char* what()
		{
			return "Unknown object type pass to factory.";
		}

		const IdentifierType GetId()
		{
			return unknownId_;
		}

	private:
		IdentifierType unknownId_;
	};

protected:
	/*StaticProductType* OnUnknownType(const IdentifierType& id)
	{
		throw Exception(id);
	}*/
};


template
<
	typename AbstractProduct,
	typename IdentifierType,
	typename ProductCreator=AbstractProduct* (*)(),  // ProductCreator是AbstractProduct的子类型
	template<typename, class> class FactoryErrorPolicy=DefaultFactoryError
>
class Factory: public FactoryErrorPolicy<IdentifierType, AbstractProduct>
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
			//return OnUnknownType(id);
			return nullptr;
		}
		return (it->second)();
	}

private:
	typedef std::map<IdentifierType, AbstractProduct> AssocMap;
	AssocMap associations_;
};


template
<
	typename AbstractProduct,
	typename ProductCreator = AbstractProduct * (*)(AbstractProduct*),
	template<typename, typename> class FactoryErrorPolicy = DefaultFactoryError
>
class CloneFactory
{
public:
	AbstractProduct* CreateObject(const AbstractProduct* model);
	bool Register(const TypeInfo&, ProductCreator creator);
	bool UnRegister(const TypeInfo&);

private:
	//typedef 
};


