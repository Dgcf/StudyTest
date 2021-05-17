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

	// ∆”ÀÿÀ„∑®
	int get_substr(const string& str, const string& sub);

	// KMPÀ„∑®
	void get_next(const string& T, int* next);
	int Index_KMP(const string& S, const string& T);
};


void TestNext();
void TestCstr();
