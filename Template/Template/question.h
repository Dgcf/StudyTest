#pragma once
#include "common.h"



template<typename T>
void print_0(T t, std::false_type)
{
	string s = std::to_string(t);
	cout << "is inter: " << s << endl;
}

template<typename T>
void print_0(T t, std::true_type)
{
	string s = t;
	cout << "is ptr: " << s << endl;
}

template<>
inline void print_0(char t, std::false_type)
{
	char x = t;	// �����char����99��
	printf("is char: %c\n", x);
}


template<typename T>
void print0(T t)
{
	print_0(t, std::is_pointer<T>());
}

void test_print();

/*
���ģ����ԣ����T�Ƿ�ָ�룬�ڱ���׶�Ҳ��� 1
T�����ͣ�const char*, char[], char, int, double
*/
template<typename T>
void wk_0(T t)
{
	/*if (strncmp(typeid(t).name(), "char", sizeof("char")) == 0)
	{
		cout << "type is char" << endl;
		return;
	}*/
	//if (std::is_pointer<T>::value)		// 1
	//{
	//	string s = t;
	//	cout << "T is pointer: " << s << endl;
	//}
	//else
	//{
	//	string s = std::to_string(t);
	//	cout << "Not Ptr: " << s << endl;
	//}

	cout << t << "'s type is: " << typeid(t).name() << endl;
}

void test_wk_0();
