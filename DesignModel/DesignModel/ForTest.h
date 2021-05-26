#pragma once

#include "Singletons.h"
#include "policy.h"
#include "typelist.h"
#include "Functor.h"

static int glo = Singletons2::Instance()->test();

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

void TestFunction(int i, double d);

void TestFunctorHandle();