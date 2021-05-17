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