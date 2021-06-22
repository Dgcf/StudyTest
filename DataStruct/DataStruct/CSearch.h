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

// �������������
	// �����������Ĳ���
	bool search_bst(BiTree T, int key, BiTree f, BiTree* p);

	// �����������Ĳ���
	bool insert_bst(BiTree* T, int key);

	// ������������ɾ��
	bool delete_data(BiTree* p);
	bool delete_bst(BiTree* T, int key);


// AVL��
	// ����ת
	void R_Rotate(AVLTree* p);

	// ����ת
	void L_Rotate(AVLTree* p);

	
#define LH 1     // ���
#define EH 0     // �ȸ�
#define RH -1    // �Ҹ�

	// ��ƽ����ת:����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת����
	void LeftBalance(AVLTree* T);
	
	// ����תƽ��
	void RightBalance(AVLTree* T);

	// ����
	int InsertAVL(AVLTree* T, int e, int* taller);
	
	
	// 2-3��


	// hash���ұ��ʵ��

};

class SearchTest {
public:
	void BinaryTest();
};

