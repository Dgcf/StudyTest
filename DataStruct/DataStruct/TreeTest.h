#pragma once

#include "common.h"

//typedef struct BiTNode
//{
//	int data;
//	BiTNode* lchild, * rchild;
//}BiTNode, * BiTree;


// fΪT�ĸ��ڵ㣬���T�Ǹ��ڵ㣬��fΪNULL
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


// �������
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
//			p->lchild = s;	// s��������������Ҫ����s��������Ӧ����pԭ����������
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
