#pragma once
#include "commmon.h"



// 1
class CMyString
{
public:
	CMyString& operator=(const CMyString& str)
	{
		if (this != &str)
		{
			if (m_pData)
			{
				delete m_pData;
				m_pData = nullptr;
			}
			m_pData = str.m_pData;
		}
		
		return *this;
	}

private:
	char* m_pData;
};

// 2
class Singleton
{
public:
	static Singleton* getInstance()
	{
		if (!instance_)
		{
			std::lock_guard<std::mutex> lc(m_);
			if (!instance_)
			{
				instance_ = new Singleton;
			}
		}
		return instance_;
	}

	// TODO 对单例的释放

private:
	static std::mutex m_;
	static Singleton* instance_;
};




class SwordOffer
{
public:
	int test_3_0(int* arr, int len)
	{
		int res = -1;
		for (int i = 0; i < len-1; ++i)
		{
			for (int j = i + 1; j < len; ++j)
			{
				if (arr[i] == arr[j])
				{
					res = arr[i];
				}
			}
		}
		return res;
	}
};


