#pragma once

#include "common.h"

//typedef struct BiTNode
//{
//	int data;
//	BiTNode* lchild, * rchild;
//}BiTNode, * BiTree;


// f为T的父节点，如果T是根节点，则f为NULL
//bool SearchBST(BiTree T, int key, BiTree f, BiTree* p)
//{
//	if (!T)
//	{
//		*p = f;
//	}
//	else if (key == T->data)
//	{
//		*p = T;
//		return true;
//	}
//	else if (key < T->data)
//	{
//		return SearchBST(T->lchild, key, T, p);
//	}
//	else
//	{
//		return SearchBST(T->rchild, key, T, p);
//	}
//}


// 插入操作
//bool InsertBST(BiTree* T, int key)
//{
//	BiTree p, s;
//	if (SearchBST(*T, key, NULL, &p))
//	{
//		s = new BiTNode;
//		s->data = key;
//		s->lchild = s->rchild = NULL;
//		if (!p)
//		{
//			*T = s;
//		}
//		else if(key < p->data)
//		{
//			p->lchild = s;	// s的左右子树不需要处理？s的左子树应该是p原来的左子树
//		}
//		else
//		{
//			p->rchild = s;
//		}
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
