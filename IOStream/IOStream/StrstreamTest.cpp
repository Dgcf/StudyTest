#include "StrstreamTest.h"


void test_strstream_test_0()
{
	ostringstream os;
	os << "dec: " << 15 << hex << "hex: " << 15 << endl;
	cout << os.str();
}