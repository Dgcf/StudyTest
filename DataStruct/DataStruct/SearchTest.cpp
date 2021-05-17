#include "SearchTest.h"


int Binary_Search(int* a, int n, int key)
{
	int index = n / 2;
	cout << "index: " << index << ", a[index] is: " << a[index] << endl;
	if (a[index] == key)
	{
		return a[index];
	}
	else if (a[index] < key)
	{
		return Binary_Search(a + index, n - index, key);
	}
	else
	{
		return Binary_Search(a, n - index, key);
	}
}


void BinaryTest()
{
	int t[] = { 2,5,9,12,14,17,29,31,35,38,42,48,57 };
	cout << "key is 9:" << endl;
	cout << "return value: " << Binary_Search(t, sizeof(t) / sizeof(int), 9) << endl;;
	cout << "key is 42:" << endl;
	cout << "return value: " << Binary_Search(t, sizeof(t) / sizeof(int), 42) << endl;
	cout << "key is 31:" << endl;
	cout << "return value: " << Binary_Search(t, sizeof(t) / sizeof(int), 31) << endl;
}
