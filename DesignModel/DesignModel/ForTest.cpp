#include "ForTest.h"

void print_var()
{
	cout << "glo: " << glo << endl;
}

typedef WidgetManager<OptNewCreator> MyWidgetManager;

void test_policy1()
{
	MyWidgetManager wm;
	wm.test();
}

void test_typelist()
{
	cout << "typelist length: " << tl::TL_Length<TYPELIST_4(int, float, double, char)>::value << endl;
	cout << "TypeAt: " << typeid(tl::TypeAt<TYPELIST_4(int, float, double, char), 3>::Result).name() << endl;
	cout << "Index of: " << tl::IndexOf<TYPELIST_4(int, float, char, char), char>::value << endl;
	cout << "Append: " << typeid(tl::Append<TYPELIST_4(int, float, double, char), string>::Result).name() << endl;
	cout << "Erase: " << typeid(tl::Erase<TYPELIST_3(int, float, double), float>::Result).name() << endl;
}
