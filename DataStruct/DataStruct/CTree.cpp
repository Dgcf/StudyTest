#include "CTree.h"

void CTree::PreOrderTraverse(BiTree T)
{
	if (nullptr == T)
	{
		return;
	}

	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void CTree::InOrderTraverse(BiTree T)
{
	if (nullptr == T)
	{
		return;
	}

	InOrderTraverse(T->lchild);
	InOrderTraverse(T->rchild);
}

void CTree::PostOrderTraverse(BiTree T)
{
	if (nullptr == T)
	{
		return;
	}
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
}

void CTree::CreateBitTree(BiTree* T)
{
	int ch = 'a';
	//int r = scanf("%d", &ch);
	if ('#' == ch)
	{
		*T = NULL;
	}
	else
	{
		*T = new BiTNode[sizeof(BiTNode)];
		if (!*T)
		{
			return;	
		}
		(*T)->data = ch;
		CreateBitTree(&(*T)->lchild);
		CreateBitTree(&(*T)->rchild);
	}
}
