#pragma once
#include <iostream>
#include "CTree.h"
using namespace std;


class CSearch
{
public:
	int sequential_search(int* a, int n, int key);

	int sequential_search2(int* a, int n, int key);

	// ���ֲ���
	int binary_search(int* a, int n, int key);
	int binary_search1(int* a, int n, int key);

	// a�����д�С����
	int binary_search_test1(int* a, int n, int v);

	// ��ֵ����

	// �����������Ĳ���
	bool search_bst(BiTree T, int key, BiTree f, BiTree* p);

	// �����������Ĳ���
	bool insert_bst(BiTree* T, int key);

	// ������������ɾ��
	bool delete_data(BiTree* p);
	bool delete_bst(BiTree* T, int key);

	//void R_Rotate(BiTree1* p);

	// AVL��
	 
	
	// 2-3��


	// hash���ұ��ʵ��

};

class SearchTest {
public:
	void BinaryTest();
};

void SearchTest11();