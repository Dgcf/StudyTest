// DesignModel.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "typelist.h"
#include "Singletons.h"
#include "ForTest.h"
#include "factory.h"
#include "Functor.h"


int main()
{
    //tl::TypeAt<TypeList<int, char>, 1> a;
    //tl::TypeAt<TypeList<int, TypeList<string,int>>, 1>::Result b= "hello";
    //cout << tl::IndexOf< TYPELIST_4(int, char, double, string), double>::value << endl;
    //typedef GenScatterHierarchy<TypeList<int, TypeList<string, TypeList<Widget, NullType>>>, Holder> WidgetInfo;
    //typedef GenScatterHierarchy<TYPELIST_3(int, string, Widget), Holder> WidgetInfo;
    //AbstractEnemyFactory f;
    //test_typelist();
    //system("pause");

    /* 测试 命令模式 */
    //test_functor();

    //test_visitor();
    //test_typetraits();
    //test_LockedStorage();
    test_ChainOfResponsibility();
}

