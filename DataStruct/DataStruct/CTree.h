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
	// ǰ�����
	void PreOrderTraverse(BiTree T);

	// �������
	void InOrderTraverse(BiTree T);

	// ��������
	void PostOrderTraverse(BiTree T);

	// ������
	void CreateBitTree(BiTree* T);
};

