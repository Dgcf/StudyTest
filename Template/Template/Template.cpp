// Template.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "ForTest.h"

class my_data
{
    my_data(const my_data& d) {}

public:
    my_data() {};
};


int main()
{
    ForTest test;
    //test.test_voidtemp();
    //test.test_varitemp();
    //test.test_pointerParam();
    // TpMemFun pm = &ForTest::test_NoTypeParam;
    // (test.*pm)();
    //test.test_special();
    test.test_func_variabletemp();
    return 0;
}

