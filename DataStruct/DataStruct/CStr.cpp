#include "CStr.h"

int CStr::get_substr(const string& str, const string& sub)
{
	int m = str.size();
	int n = sub.size();
	int len = m - n;
	
	int index = -1;
	for (size_t i = 0; i <= len; i++)
	{
		int k = i;
		int sub_index = 0;
		while (str[k] == sub[sub_index] && sub_index < n)
		{
			++k;
			++sub_index;
		}
		if (sub_index == n)
		{
			return i;
		}
	}

	return index;
}

void CStr::get_next(const string& T, int* next)
{
	int i = 0, j = -1;
	next[0] = -1;
	while (i < T.size()-1)
	{
		if (j == -1 || T[i] == T[j])  // T[i]表示后缀字符,T[j]表示前缀字符
		{
			++j;
			++i;
			if (T[i] == T[j])
			{
				next[i] = next[j];
			}
			else
			{
				next[i] = j;
			}
		}
		else
		{
			j = next[j];  // 若字符不相同，则j值回溯
		}
	}
}

int CStr::Index_KMP(const string& S, const string& T)
{
	int i = 0;
	int j = 0;

	int sl = S.size();
	int tl = T.size();
	int* next = new int[tl];
	memset(next, 0, sizeof(*next));
	get_next(T, next);
	
	while (i < sl && j < tl)
	{
		if (j == -1 || S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= T.size())
	{
		return i - T.length();
	}
	
	return -1;
}



void TestNext()
{
	CStr ct;
	string s = "abcdefghijklmn";
	int next[255];
	memset(next, 0, sizeof(next));
	ct.get_next(s, next);
	int x = 99;
}

void TestCstr()
{
	CStr ct;
	int index = ct.Index_KMP("aaaaaaax", "aax");
	cout << "index is: " << index << endl;

	//TestNext();
}
