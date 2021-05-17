#include <stdio.h>

int binary_search(int* t, int l, int key)
{
	int start = 0;
	int end = l-1;
	int index = -1;
	
	while(index)
	{
		index = (end-start)/2;
		if(key > t[index])
		{
			start = index;
		}
		else if(key < t[index])
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