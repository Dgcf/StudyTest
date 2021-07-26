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
	// 前序遍历
	void PreOrderTraverse(BiTree T);

	// 中序遍历
	void InOrderTraverse(BiTree T);

	// 后续遍历
	void PostOrderTraverse(BiTree T);

	// 创建树
	void CreateBitTree(BiTree* T);

	// 查找
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

	// 右旋
	void R_Rotate(AVLTree* p)
	{
		AVLTree L;
		L = (*p)->lchild;
		(*p)->lchild = L->rchild;
		L->rchild = (*p);
		*p = L;
	}

	// 左旋
	void L_Rotate(AVLTree* p)
	{
		AVLTree L = (*p)->rchild;
		(*p)->rchild = L->lchild;
		L->lchild = (*p);
		*p = L;
	}

#define LH 1     // 左高
#define EH 0     // 等高
#define RH -1    // 右高

	// 左平衡旋转处理
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

