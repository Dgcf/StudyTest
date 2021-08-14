#pragma once
#include "CTree.h"
#include "DynamicProgram.h"
#include "SwordOffer.h"
#include "TwentyTraining.h"


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

	void rt()
	{
		ListNode* l1 = new ListNode(2);
		l1->next = new ListNode(4);
		l1->next->next = new ListNode(3);
		ListNode* l2 = new ListNode(5);
		l2->next = new ListNode(6);
		l2->next->next = new ListNode(4);
		t_.addTwoNumbers(l1, l2);
	}
	
	void tt()
	{
		cout << t_.lengthOfLongestSubstring("ynyo") << endl;
	}

	void ll()
	{
		ListNode* node(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr))))));
		ListNode* node1(new ListNode(1, new ListNode(2, nullptr)));
		t_.reverseList(node1);
	}

	void test_search()
	{
		vector<int> v{ 1,2,4,4,5 };
		vector<int> v2{ 1,1,1,1,1 };
		
		//cout << t_.search(v, 4) << endl;
		//cout << t_.search(v, 3) << endl;
		cout << t_.search(v2, 1) << endl;
	}
private:
	DynamicProgram p_;
	SwordOffer s_;
	TwentyTraining t_;
};

