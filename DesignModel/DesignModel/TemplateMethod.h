#pragma once

#include "common.h"

class AbstractClass
{
public:
	void TemplateMethod()
	{
		cout << "Enter in TemplateMethod" << endl;
		DoPrimitiveOperator1();
		DoPrimitiveOperator2();
		cout << "Leave TemplateMethod" << endl;
	}

protected:
	virtual void DoPrimitiveOperator1() = 0;
	virtual void DoPrimitiveOperator2() = 0;
};


class ConcreteClassA : public AbstractClass
{
public:
	void DoPrimitiveOperator1()
	{
		cout << "Enter in ConcreteClassA::PrimitiveOperator1" << endl;
	}

	void DoPrimitiveOperator2()
	{
		cout << "Enter in ConcreteClassA::PrimitiveOperator2" << endl;
	}
};


class ConcreteClassB : public AbstractClass
{
public:
	void DoPrimitiveOperator1()
	{
		cout << "Enter in ConcreteClassB::PrimitiveOperator1" << endl;
	}

	void DoPrimitiveOperator2()
	{
		cout << "Enter in ConcreteClassB::PrimitiveOperator2" << endl;
	}
};