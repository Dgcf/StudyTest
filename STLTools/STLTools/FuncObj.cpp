#include "FuncObj.h"

int g_iTest1 = 12;

void test_bind_f1(int a, string b, vector<int> c, const char* d, double e)
{
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "vector: ";
	for (size_t i = 0; i < c.size(); i++)
	{
		cout << c.at(i) << " ";
	}
	cout << endl;
	printf("d: %s\n", d);
	cout << "e: " << e << endl;
}

void test_bind_0()
{
	int a1 = 34;
	string b1 = "study";
	vector<int> c1 = { 1,2,3,4,5,6,7,8,9,0 };
	const char* d1 = "good";
	double e1 = 3.1415;
	std::function<void(double, string)> f = std::bind(test_bind_f1, a1, std::placeholders::_2, c1, d1, std::placeholders::_1);
	f(e1, b1);
}

// 测参数
void test_lambda_0()
{
	int a = 12;
	string b("hundsun");
	auto f1 = [](int i) {
		return i + 19;
	};
	cout << f1(a) << endl;
}

// 测局部捕获值
void test_lambda_1()
{
	int a = 12;
	string b("hundsun");
	auto f2 = [a, b]()
	{
		cout << a << endl;
		cout << b << endl;
	};
	f2();
}

//测全局变量
void test_lambda_2()
{
	auto f3 = []()
	{
		int r = gs_iTest0 + g_iTest1;
		return r;
	};
	cout << f3() << endl;
}

// 测修改
void test_lambda_3()
{
	int a = 12;
	string b("hundsun");
	auto f4 = [a, b]() mutable
	{
		cout << ++g_iTest1 << endl;
		cout << ++a << endl;
	};
}
