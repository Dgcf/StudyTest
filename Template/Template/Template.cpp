// Template.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "common.h"
#include "tem.h"
#include "question.h"
#include "wkcd.h"
#include "typetraits.h"
#include "returntype.h"
#include "TestType.h"
#include "FuncTemp.h"
#include "CTemBind.h"

struct X
{
    int a1;
    int a2;
    X()
    {
        memset(this, 0, sizeof(X));
    }
};
struct EmptyStruct
{
    char empty[0];
};


int main()
{
    //cout << sizeof(EmptyStruct) << endl;
    const char* s = "hello";
    //const_test(s);
    return 0;
}

