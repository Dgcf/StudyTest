#pragma once

#include "common.h"
using namespace std::rel_ops;
void test_pair();

/*******************
函数对象
*******************/
class IntSequence
{
private:
	int value;

public:
	IntSequence(int initialValue) :
		value(initialValue) {
	}

	int operator()()
	{
		cout << "operator()" << endl;
		return ++value;
	}

	int operator()(int x)
	{
		cout << "operator()" << endl;
		value += x;
		return value;
	}

	void print() const
	{
		cout << value << endl;
	}
};

void test_IntSequence();


/*************************
随机数测试
*************************/
void test_random_0();

// 引擎
void printNumbers(std::default_random_engine& dre);
void test_engine();

//