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

int main()
{
    //Macro_ToStr();
    Ptr()
    return 0;
}

