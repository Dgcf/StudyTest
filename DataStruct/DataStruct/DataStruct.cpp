// DataStruct.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Unorder.h"
#include "SetMapTest.h"
#include "SearchTest.h"
#include "CSort.h"
#include "CStr.h"
#include "CSearch.h"

int binary_search(int* t, int len, int key)
{
	int start = 0;
	int end = len ;
	int index = -1;  

	while (start <= len)
	{
		index = (end + start) / 2;
		if (key > t[index])
		{
			start = index;
		}
		else if (key < t[index])
		{
			end = index;
		}
		else
		{
			return index;
		}
	}
	return index;
}

int main()
{
	TestCstr();
    system("pause");

}

