#pragma once
#include "common.h"
//#include "Test.h"
extern int g_iTest;
extern const int g_ciTest;

void test_static_var0();

class MyTest1
{
public:
	MyTest1():x("good"), iTest0(1), iTest1(nullptr)
	{

	}

	void print() const
	{
		cout << x << endl;
		cout << ++iTest0 << endl;
	}

	void print()
	{
		x += " morning";
		cout << x << endl;
		//cout << ++iTest0 << endl;
	}

	void test_Null()
	{
		cout << sizeof(nullTest0) << endl;
	}

private:
	string x;
	mutable int iTest0;
	int* iTest1;
	nullptr_t nullTest0;
};

void test_MyTest1_0();

int testparams(int count, ...);


template<typename ... Args> 
void g(Args ... args) 
{
	cout << sizeof...(Args) << endl;
	cout << sizeof...(args) << endl;
}

template<typename T, typename... Args>
ostream& print(ostream& os, const T& t, const Args&... rest)//扩展模板参数包Args，将模式const Args&应用到模板参数Args
{                      //中的每个元素，因此，此模式的扩展结果是一个逗号分隔的零个或多个类型的列表，每个类型都是const type&
	os << t << ", ";
	return print(os, rest...);    // 扩展rest，为print调用生成实参列表
}

class ABC
{
public:
	ABC() {}
	ABC(ABC&&) {}
};

class Ptr
{
public:
	Ptr(std::unique_ptr<ABC>& p)
	:p_(std::move(p))
	{}

private:
	std::unique_ptr<ABC> p_;
};

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int key1 = nums[0];
        vector<int>::iterator it;
        for (vector<int>::iterator iter1 = nums.begin(); iter1 != nums.end(); ++iter1)
        {
            if (key1 < *iter1)
            {
                it = iter1;
                key1 = *iter1;
            }
        }
        nums.erase(it);

        int key2 = nums[0];
        for (vector<int>::iterator iter2 = nums.begin(); iter2 != nums.end(); ++iter2)
        {
            if (key2 < *iter2)
            {
                it = iter2;
                key2 = *iter2;
            }
        }
        nums.erase(it);

        int key3 = nums[0];
        for (vector<int>::iterator iter3 = nums.begin(); iter3 != nums.end(); ++iter3)
        {
            if (key3 > *iter3)
            {
                it = iter3;
                key3 = *iter3;
            }
        }
        nums.erase(it);

        int key4 = nums[0];
        for (vector<int>::iterator iter4 = nums.begin(); iter4 != nums.end(); ++iter4)
        {
            if (key4 > *iter4)
            {
                it = iter4;
                key4 = *iter4;
            }
        }
        nums.erase(it);

        return (key1 * key2) - (key3 * key4);
    }


};
