#pragma once
#include <iostream>
#include "CTree.h"
using namespace std;


typedef struct BiTNode1
{
	int data;
	int bf;
	BiTNode1* lchild, * rchild;
}BiTNode1, * BiTree1;


class CSearch
{
public:
	int sequential_search(int* a, int n, int key);

	int sequential_search2(int* a, int n, int key);

	// ���ֲ���
	int binary_search(int* a, int n, int key);
	int binary_search1(int* a, int n, int key);

	// ��ֵ����

	// �����������Ĳ���
	bool search_bst(BiTree T, int key, BiTree f, BiTree* p);

	// �����������Ĳ���
	bool insert_bst(BiTree* T, int key);

	// ������������ɾ��
	bool delete_data(BiTree* p);
	bool delete_bst(BiTree* T, int key);

	void R_Rotate(BiTree1* p);

	// 2-3��


	// hash���ұ��ʵ��

};

class SearchTest {
public:
	void BinaryTest();
};

void SearchTest11();