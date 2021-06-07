#pragma once
#include "Derived.h"


void test_Derived();

void test_memptr();

class NoDefault
{
public:
    NoDefault(int i) :i_(i)
    {}
public:
    int i_;
};

class C1
{
public:
    NoDefault nf;
};

void test_Class();