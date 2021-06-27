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
	//std::enable_if_t
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
	//cout << "type: " << typeid(TypeAt<2, int, float, double, string>).name() << endl;
}

void ForTest::test_sfinae()
{
	/*T1<int> t(10);
	T1<int> t1(1.2);*/
	T1<string, int, float, string> t(10);
	
	t.GetTest<2>();

	// 测试模板参数包为0
	//T1<int> t2(2.3);
	//t2.GetTest<0>();
	//cout << s << endl;
	//std::shared_ptr
}

void ForTest::test_variable_type()
{
	function_traits<int, float, double, string> d;
	string s = d.GetNum<3>();
	cout << s << endl;
	cout << "type name: " << typeid(function_traits<int, float, double, string>::arg<3>::type).name() << endl;
}

void ForTest::test_stack()
{
	int x = 10;
	list_node<int> l(x, nullptr);
}

void ForTest::test_NoTypeParam()
{
	int ar[] = { 1,2,3,4,5,6,7,8 };
	//foreach<int, print<int>>(ar, 8);
	foreach1<int,print1>(ar, 8);
}

int global_variable = 0;

void ForTest::test_pointerParam()
{
	wrapper<&global_variable> g;
	g.set(1);
	cout << g.get() << endl;

	wrapper2<global_variable> g1;
	g1.set(2);
	cout << g1.get() << endl;

	// 局部变量或指针不可用于模板参数
	// int local_variable = 2;
	// wrapper<&local_variable> g2;
}
