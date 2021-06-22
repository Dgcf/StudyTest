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

// 二叉查找树操作
	// 二叉排序树的查找
	bool search_bst(BiTree T, int key, BiTree f, BiTree* p);

	// 二叉排序树的插入
	bool insert_bst(BiTree* T, int key);

	// 二叉排序树的删除
	bool delete_data(BiTree* p);
	bool delete_bst(BiTree* T, int key);


// AVL树
	// 右旋转
	void R_Rotate(AVLTree* p);

	// 左旋转
	void L_Rotate(AVLTree* p);

	
#define LH 1     // 左高
#define EH 0     // 等高
#define RH -1    // 右高

	// 左平衡旋转:对以指针T所指结点为根的二叉树做左平衡旋转处理
	void LeftBalance(AVLTree* T);
	
	// 右旋转平衡
	void RightBalance(AVLTree* T);

	// 插入
	int InsertAVL(AVLTree* T, int e, int* taller);
	
	
	// 2-3树


	// hash查找表的实现

};

class SearchTest {
public:
	void BinaryTest();
};

