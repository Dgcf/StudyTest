#pragma once
#include "CList.h"
#include "CSearch.h"
#include "CSort.h"
#include "CStr.h"
#include "CTree.h"
#include "CVector.h"
#include "Unorder.h"



class ForTest
{
public:
	void test_Search();

// map test
	void map_test_create0();

// set test
	void set_test_create0();

	// Æ½ºâ¶þ²æÊ÷
	void test_avlinsert();

private:
	CSearch search_;
};

