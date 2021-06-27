// Template.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "ForTest.h"


int main()
{
    ForTest test;
    //test.test_voidtemp();
    //test.test_varitemp();
    //test.test_pointerParam();
    TpMemFun pm = &ForTest::test_NoTypeParam;
    (test.*pm)();
    return 0;
}

