// DesignModel.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "typelist.h"
#include "Singletons.h"
#include "ForTest.h"

class Widget{};

template<class T>
struct Holder
{
    T value_;
};



int main()
{
    //tl::TypeAt<TypeList<int, char>, 1> a;
    //tl::TypeAt<TypeList<int, TypeList<string,int>>, 1>::Result b= "hello";
    //cout << tl::IndexOf< TYPELIST_4(int, char, double, string), double>::value << endl;
    typedef GenScatterHierarchy<TypeList<int, TypeList<string, TypeList<Widget, NullType>>>, Holder> WidgetInfo;
}

