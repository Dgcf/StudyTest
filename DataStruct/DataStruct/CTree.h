#pragma once
#include "common.h"


typedef struct BiTNode
{
	int data;
	BiTNode* lchild, * rchild;
}BiTNode, * BiTree;


typedef struct AVLTNode
{
	int data;
	int bf;
	AVLTNode* lchild, * rchild;
}AVLTNode, * AVLTree;


class CTree
{
public:
	// ǰ�����
	void PreOrderTraverse(BiTree T);

	// �������
	void InOrderTraverse(BiTree T);

	// ��������
	void PostOrderTraverse(BiTree T);

	// ������
	void CreateBitTree(BiTree* T);

	// ����
	BiTree* SearchBST(BiTree* t, int val)
	{
		if (val == (*t)->data)
		{
			return t;
		}

		if (val < (*t)->data)
		{
			SearchBST(&((*t)->lchild), val);
		}
		else
		{
			SearchBST((&(*t)->rchild), val);
		}
	}

	// ����
	void R_Rotate(AVLTree* p)
	{
		AVLTree L;
		L = (*p)->lchild;
		(*p)->lchild = L->rchild;
		L->rchild = (*p);
		*p = L;
	}

	// ����
	void L_Rotate(AVLTree* p)
	{
		AVLTree L = (*p)->rchild;
		(*p)->rchild = L->lchild;
		L->lchild = (*p);
		*p = L;
	}

#define LH 1     // ���
#define EH 0     // �ȸ�
#define RH -1    // �Ҹ�

	// ��ƽ����ת����
	void LeftBalance(AVLTree* T)
	{
		AVLTree L, Lr;
		L = (*T)->lchild;
		switch (L->bf)
		{
		case LH:
			(*T)->bf = L->bf = EH;
			break;
		default:
			break;
		}
	}
};

