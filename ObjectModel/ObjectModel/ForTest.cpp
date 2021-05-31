#include "ForTest.h"

void test_Derived()
{
	DerivedMay dm;
	BaseMay m = static_cast<BaseMay>(dm);
}
