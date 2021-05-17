#include "FlagsTest.h"

void test_flag_0()
{
	std::ios::fmtflags oldFlags = cout.flags();
	cout.setf(ios::showpos | ios::showbase | ios::uppercase);
	cout.setf(ios::internal, ios::adjustfield);

	int x = 12;
	cout << std::hex << x << std::endl;
	cout.flags(oldFlags);
}

void test_set_0()
{
	std::cout << std::setw(8) << std::setfill('_') << -3.14 << ' ' << 42 << std::endl;
	std::cout << setw(8) << "sum: " << setw(8) << 42 << std::endl;
}