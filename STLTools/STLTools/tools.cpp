#include "tools.h"

void test_pair()
{
	std::pair<int, string> p1(10, "good");
	cout << "first: " << p1.first << "\tsecond: " << p1.second << endl;
	cout << "first: " << get<0>(p1) << "\tsecond: " << get<1>(p1) << endl;
}

void test_IntSequence()
{
	// 以类名调用之
	cout << IntSequence(10)(15) << endl;
	// 以类对象调用
	IntSequence i(123);
	i(14);
	i.print();
}

void test_random_0()
{
	std::default_random_engine dre;
	std::uniform_int_distribution<int> di(10, 20);
	for (int i = 0; i < 20; ++i)
	{
		cout << di(dre) << " ";
	}
	cout << std::endl;

	std::uniform_real_distribution<double> dr(10, 20);
	for (int i = 0; i < 8; ++i)
	{
		std::cout << dr(dre) << " ";
	}
	cout << std::endl;
}

void printNumbers(std::default_random_engine& dre)
{
	for (int i = 0; i < 6; ++i)
	{
		cout << dre() << " ";
	}
	cout << std::endl;
}

void test_engine()
{
	std::default_random_engine dre;
	printNumbers(dre);

	std::default_random_engine dre1;
	printNumbers(dre1);

	std::default_random_engine dre2;
	printNumbers(dre2);
}
