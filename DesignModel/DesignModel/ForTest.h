#pragma once

#include "Singletons.h"
#include "policy.h"
#include "typelist.h"
#include "Functor.h"
#include "visitable.h"
#include "visitor.h"
#include "typetraits.h"
#include "SmartPtr.h"
#include "ChainOfResponsibility.h"
#include "Mediator.h"
#include "Memento.h"
#include "decorator.h"
#include "Command.h"
#include "Observer.h"
#include "TemplateMethod.h"

// static int glo = Singletons2::Instance()->test();

void print_var();

void test_policy1();

void test_typelist();

void test_GenScatterHierarchy();

struct TestFunctor 
{
	void operator()(int i, double d)
	{
		cout << "TestFunctor::operator()(" << i << ", " << d << ") called.\n";
	}
};

void TestFunction(int& i, double d);



typedef void(MY_FUNC)(int&, double);

void TestFunctorHandle();

void test_functor();

void test_abstractenemyfactory();

void test_visitor();

void test_typetraits();

class TestTypeTraits
{
public:
	void func1(const string& str)
	{
		cout << "TestTypeTraits::func1" << str << endl;
	}
};

void test_GetImpl_DefaultSPStorage();

void test_LockedStorage();

void test_ChainOfResponsibility();

void test_MediatorA();

void test_Memento();

void test_Decorator();

void test_Command();

void test_Observer();

void test_TemplateMethod();

void test_Visitor();
