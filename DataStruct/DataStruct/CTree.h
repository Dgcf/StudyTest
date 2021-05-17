#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef struct BiTNode
{
	int data;
	BiTNode* lchild, * rchild;
}BiTNode, * BiTree;


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
};

