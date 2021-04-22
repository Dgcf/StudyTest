// BasicSum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Test.h"
#include "MyTest1.h";
#include "MacroTest.h"
//extern int g_iTest;

template<typename T>
void print(T& t)
{
    cout << "L";
}

template<typename T>
void print(T&& t)
{
    cout << "R";
}

template<typename T>
void test(T&& t)
{
    print(t);
    print(std::forward<T>(t));
    print(std::move(t));
    cout << ": ";
}

void simulate()
{
	cout << "请输入要进行的运算，a为+，b为-，c为*（乘法），d为/（除法）,q退出计算:" << endl;
	
	string s;
	while ("q" != s)
	{
		cin >> s;
		if ("a" == s)
		{
			cout << "请输入要进行加法运算的数字，输入一个数字后按Enter键输入第二个数字,再次按Enter键得到计算结果：" << endl;
			int a = 0;
			cin >> a;
			int b = 0;
			cin >> b;
			cout << a << " + " << b << " = " << a + b << endl;
			cout << "请计算输入并计算，如需退出请输入q" << endl;
		}
		else if ("b" == s)
		{
			cout << "请输入要进行减法运算的数字，输入一个数字后按Enter键输入第二个数字,再次按Enter键得到计算结果：" << endl;
			int a = 0;
			cin >> a;
			int b = 0;
			cin >> b;
			cout << a << " - " << b << " = " << a - b << endl;
			cout << "请计算输入并计算，如需退出请输入q" << endl;
		}
		else if ("c" == s)
		{
			cout << "请输入要进行乘法运算的数字，输入一个数字后按Enter键输入第二个数字,再次按Enter键得到计算结果：" << endl;
			int a = 0;
			cin >> a;
			int b = 0;
			cin >> b;
			cout << a << " * " << b << " = " << a * b << endl;
			cout << "请计算输入并计算，如需退出请输入q" << endl;
		}
		else if ("d" == s)
		{
			cout << "请输入要进行除法运算的数字，输入一个数字后按Enter键输入第二个数字,再次按Enter键得到计算结果：" << endl;
			int a = 0;
			cin >> a;
			int b = 0;
			cin >> b;
			cout << a << " / " << b << " = " << a / b << endl;
			cout << "请计算输入并计算，如需退出请输入q" << endl;
		}
		else if ("q" == s)
		{
			cout << "再见！" << endl;
		}
		else
		{
			cout << "不合法的输入，请按照提示重新输入，如需退出请输入q" << endl;
		}
	}
	
}

struct A01 {
	int x;
	char y;
	double z;
};

struct A02
{
	int x;
	A01 a01;
	double d;
};

struct A03 {
	int x;
	A01 a01;
	char c;
};

template<class T>
class multi_span
{
	std::vector<T*> data_;
	std::size_t size_{ 0 };

public:
	T** data() const
	{
		return data_.data();
	}
};

class abc_d
{
public:
	abc_d(int a):a_(a){}

	int data() const
	{
		return a_;
	}

	A01* const * dafa() const 
	{
		return data_.data();
	}

	int a_;
	std::vector<A01*> data_;
};

void t4()
{
	int a = 0, b = 0;
	if (cin >> a)
	{
		int c = 1;
		while (cin>>b)
		{
			if (a == b)
			{
				++c;
			}
			else
			{
				cout << a << "occurs" << c << "times" << endl;
				a = b;
				c = 1;
			}
		}
		cout << a << "occurs" << c << "times" << endl;
	}
}

int main()
{
	/*const char* item_name[] = {
		"msgtype", "business_date", "business_time", "quote_mark", "batch_no",
		"entrust_no", "cancel_entrust_no", "report_no", "account_code", "combi_no" };

	for (size_t i = 0; i < sizeof(item_name)/sizeof(*item_name); i++)
	{
		cout << *(item_name + i) << endl;
		cout << strlen(*(item_name + i)) << endl;
	}*/
	t4();
	system("pause");
    return 0;
}

