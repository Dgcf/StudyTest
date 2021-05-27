#pragma once

#include "visitor.h"

class BaseVisitor;

template<typename T, typename Y>
class DefaultCatchAll {};

template
<
	typename R=void,
	template<typename, typename> class CatchAll=DefaultCatchAll
>
class BaseVisitable
{
public:
	typedef R ReturnType;
	virtual ~BaseVisitable() {}
	virtual ReturnType Accept(BaseVisitor&) = 0;

protected:
	template<typename T>
	static ReturnType AcceptImpl(T& visited, BaseVisitor& guest)
	{
		if (Visitor<T>* p = dynamic_cast<Visitor<T>*>(&guest))
		{
			return p->Visit(visited);
		}
		return ReturnType();
	}

};

#define DEFINE_VISITABLE()  \
	virtual ReturnType Accept(BaseVisitor& guest)  \
	{ return AcceptImpl(*this, guest); }


class DocElement : public BaseVisitable<>
{
public:
	DEFINE_VISITABLE()
};

class Paragraph : public DocElement
{
public:
	DEFINE_VISITABLE()
};

class MyConcreteVisitor : public BaseVisitor, public Visitor<DocElement>, public Visitor<Paragraph>
{
public:
	void Visit(DocElement&)
	{
		cout << "Visit(DocElement&) \n" << endl;
	}

	void Visit(Paragraph&)
	{
		cout << "Visit(Paragraph&) \n" << endl;
	}
};

