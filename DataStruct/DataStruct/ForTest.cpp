#include "ForTest.h"

void ForTest::test_Search()
{
	int t[] = { 2,5,9,12,14,17,29,31,35,38,42,48,57 };
	int index = 0;
	//index = search_.binary_search_test1(t, sizeof(t) / sizeof(int), 35);
	//cout << "index: " << index << endl;
	//index = search_.binary_search_test1(t, sizeof(t) / sizeof(int), 46);
	//cout << "index: " << index << endl;
	index = search_.binary_search_test1(t, sizeof(t) / sizeof(int), 5);
	cout << "index: " << index << endl;
}
