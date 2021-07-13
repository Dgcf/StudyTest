#pragma once
#include "commmon.h"


class DynamicProgram
{
public:
	/// ��Ŀ������
	/// һ�������У�ѡ�������ڵ�������Ӻ��������֣�����������ֵ
	///
	// �ݹ�
	int get_opt1(int* arr, int index)
	{
		if (0 == index)
		{
			return arr[0];
		}
		else if (1 == index)
		{
			return std::max(arr[0], arr[1]);
		}
		else
		{
			int a = get_opt1(arr, index - 1);
			int b = get_opt1(arr, index - 2) + arr[index];
			return std::max(a, b);
		}

		return 0;
	}

	// ���鱣��
	int get_opt2(int* arr, int len)
	{
		if (len == 0)
		{
			return 0;
		}
		else if (len == 1)
		{
			return arr[0];
		}
		else if (len == 2)
		{
			return std::max(arr[0], arr[1]);
		}
		else
		{
			int* v = new int[len];
			memset(v, 0, len);
			v[0] = arr[0];
			v[1] = std::max(arr[0], arr[1]);
			for (int i = 2; i < len; ++i)
			{
				int x = v[i - 2] + arr[i];
				int y = v[i - 1];
				v[i] = std::max(x, y);
			}
			return v[len - 1];
		}
		return 0;
		
	}

    // һ�����������һ���������֣�����ܴ�������ѡ����Ϊ�������ֵ���Ϸ���true������false
	// ����arr[]={3,34,4,12,5,2};s=9,����ֵΪtrue
	// ��������
	bool get_value(int* arr, int len, int v)
	{
		for (int i = 0,j=i+1; i < len; ++i)
		{
			if (arr[i] == v)
			{
				return true;
			}
		}
		return false;
	}

	
};

