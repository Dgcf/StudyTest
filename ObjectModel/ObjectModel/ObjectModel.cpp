// ObjectModel.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "common.h"
#include "Model.h"
#include "FuncSemantic.h"
#include "DataSeman.h"
#include "MoveTest.h"
#include "CopySemantic.h"
#include "ForTest.h"

std::unique_ptr<int> v()
{
    std::unique_ptr<int> a(new int(2));
    return a;
}

// 看下栈是向下增长还是向上增长
void Test_stack()
{
    int a0 = 0;
    int a1 = 1;
    int* a11 = new int(21);
    int a2 = 2;
    int* a21 = new int(32);
    int a3 = 3;
    cout << "ssss" << endl;
}

class NoDefault
{

};

int main()
{
    test_memptr();
}

