#pragma once
#include "common.h"

class CStr
{
private:
	string ori_;

public:
	CStr():
		ori_("goodgoole")
	{}

	// �����㷨
	int get_substr(const string& str, const string& sub);

	// KMP�㷨
	void get_next(const string& T, int* next);
	int Index_KMP(const string& S, const string& T);
};


void TestNext();
void TestCstr();
