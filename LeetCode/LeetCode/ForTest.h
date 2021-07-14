#pragma once
#include "CTree.h"
#include "DynamicProgram.h"
#include "SwordOffer.h"


class ForTest
{
private:
	CTree tree_;

public:
	void test_94();

// ¶¯Ì¬¹æ»®
public:
	void test_dynamic_pro1()
	{
		int a[] = { 1, 2, 4, 1, 7, 8, 3 };
		int b[] = { 4,1,1,9.1 };
		int max = p_.get_opt2(b, sizeof(b) / sizeof(int));
		cout << "test_dynamic_pro1: " << max << endl;
	}



public:
	void test_sword_0()
	{
		int a[] = { 2,3,1,0,2,5,3 };
		int s = s_.test_3_0(a, sizeof(a) / sizeof(int));
		cout << s << endl;
	}

	void test_erchashu()
	{
		tree_.generateTree(3);
	}
private:
	DynamicProgram p_;
	SwordOffer s_;
};

