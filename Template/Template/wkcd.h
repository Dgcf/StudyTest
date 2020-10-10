#pragma once
#include "common.h"

// ����typedef����������ܲ���ת��
typedef int UINT;



class Test
{
public:
	Test(int i);

private:
	int i_;
};

// ������ģ�����
template<typename T, uint32_t iX>
void test_tem()
{
	T t(12);
	cout << "�����ͣ�" << iX << endl;
}

// ����һ���࣬������ģ���Ա
class Entrust
{
public:
	Entrust() {}

	void hello()
	{
		cout << "hello" << endl;
	}

	template<typename T>
	void print_0(T t, std::false_type)
	{
		string s = std::to_string(t);
		cout << "is inter: " << s << endl;
		hello();
	}

	template<typename T>
	void print_0(T t, std::true_type)
	{
		string s = t;
		cout << "is ptr: " << s << endl;
		hello();
	}

	template<>
	void print_0(char t, std::false_type)
	{
		char x = t;	// �����char����99��
		printf("is char: %c\n", x);
		hello();
	}


	template<typename T>
	void print0(T t)
	{
		print_0(t, std::is_pointer<T>());
	}

	void test()
	{
		long a = 10;
		char b[32];
		strncpy(b, "hello", sizeof("hello"));
		const char* c = "food";
		double d = 12.34;
		char e = 'a';
		print0(a);
		print0(b);
		print0(c);
		print0(d);
		print0(e);
	}
};

