#include "ContectTest.h"

void test_connect_1()
{
	ostream hexout(cout.rdbuf());
	hexout.setf(ios::hex, ios::basefield);
	hexout.setf(ios::showbase);
	hexout << "hexout:" << 177 << endl;
	cout << "cout: " << 177 << endl;
}