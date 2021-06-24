#include "ForTest.h"

void ForTest::test_conjunction()
{
	func(1, 2, 3);
	func(1, 2, "hello!");
}

void ForTest::test_is_same_type()
{
	cout << (is_same_v<int, int> ? ("is same") : ("not is same")) << endl;

	std::cout << std::is_same_v<int, std::int32_t> << ' ';  // ~ true
	std::cout << std::is_same_v<int, std::int64_t> << '\n'; // ~ false

	long double num1 = 1.0;
	long double num2 = 2.0;
	std::cout << std::is_same_v<decltype(num1), decltype(num2)> << '\n'; // true
}

void ForTest::test_varitemp()
{
	cout << tem_str1<int, int> << endl;
	cout << tem_str1<int, double> << endl;
}

void ForTest::test_addressof()
{
	int* pi = new int(42);
	Ptr<int> p(pi);
	f(&p);                 // calls int** overload
	f(std::addressof(p));
}

void ForTest::test_voidtemp()
{
	VoidTest<void> v;
	VoidTest<int> v1;
	//T t(10);
}

void ForTest::test_variable_parm()
{
	cout << "type: " << typeid(TypeAt<2, int, float, double, string>).name() << endl;
}
