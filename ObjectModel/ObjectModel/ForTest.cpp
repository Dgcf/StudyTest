#include "ForTest.h"

typedef void(BaseMay::* TpMemFn)();


void test_Derived()
{
	DerivedMay dm;
	BaseMay m = static_cast<BaseMay>(dm);
}

void test_memptr()
{
	TpMemFn pAc = &BaseMay::Eat;

	BaseMay bm;
	(bm.*pAc)();
}


void test_Class()
{
	ABC a;

}