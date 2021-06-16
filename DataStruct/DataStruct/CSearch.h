#pragma once
#include <iostream>
#include "CTree.h"
using namespace std;


class CSearch
{
public:
	int sequential_search(int* a, int n, int key);

	int sequential_search2(int* a, int n, int key);

	// 二分查找
	int binary_search(int* a, int n, int key);
	int binary_search1(int* a, int n, int key);

	// a的排列从小到大
	int binary_search_test1(int* a, int n, int v);

	// 插值查找

	// 二叉排序树的查找
	bool search_bst(BiTree T, int key, BiTree f, BiTree* p);

	// 二叉排序树的插入
	bool insert_bst(BiTree* T, int key);

	// 二叉排序树的删除
	bool delete_data(BiTree* p);
	bool delete_bst(BiTree* T, int key);

	//void R_Rotate(BiTree1* p);

	// AVL树
	 
	
	// 2-3树


	// hash查找表的实现

};

class SearchTest {
public:
	void BinaryTest();
};

void SearchTest11();