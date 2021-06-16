#include "CSearch.h"

int CSearch::sequential_search(int* a, int n, int key)
{
	int index = -1;
	for (int i = 0; i < n; i++)  
	{
		if (key == a[i])
		{
			return i;
		}
	}
	return index;
}

// 上种方式每次循环都要对i是否小于n做判断，优化如下
// 但是这个方法要求第0个值为key，大部分实际情况下并不具备
int CSearch::sequential_search2(int* a, int n, int key)
{
	a[0] = key;
	int index = n;
	while (a[index] != key)
	{
		index--;
	}
	return index;
}

int CSearch::binary_search(int* a, int n, int key)
{
	int low = 0;
	int high = n;
	int mid = 0;
	int index = -1;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (a[mid] < key)
		{
			low = mid;
		}
		else if (a[mid] > key)
		{
			high = mid;
		}
		else
		{
			return mid;
		}
	}
	return index;
}

int CSearch::binary_search1(int* a, int n, int key)
{
	int low, high, mid;
	low = 0;
	high = n-1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key < a[mid])
		{
			high = mid - 1;
		}
		else if (key > a[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int CSearch::binary_search_test1(int* a, int n, int v)
{
	if (!a || n <= 0)
	{
		return -1;
	}

	int start = 0;
	int end = n - 1;
	int mid = -1;
	int res = -1;
	
	while (start <= end)
	{
		mid = (end + start) / 2;
		if (v > a[mid])
		{
			start = mid + 1;
		}
		else if (v < a[mid])
		{
			end = mid - 1;
		}
		else
		{
			return mid;
		}
	}

	return res;
}

bool CSearch::search_bst(BiTree T, int key, BiTree f, BiTree* p)
{
	if (!T) {
		*p = f;
		return false;
	}
	else if(key == T->data)
	{
		*p = T;
		return true;
	}
	else if (key < T->data)
	{
		search_bst(T->lchild, key, T, p);
	}
	else if (key > T->data)
	{
		search_bst(T->rchild, key, T, p);
	}
}

bool CSearch::insert_bst(BiTree* T, int key)
{
	BiTree p, s;
	if (!search_bst(*T, key, NULL, &p))
	{
		s = new BiTNode;
		s->data = key;
		s->lchild = s->rchild = nullptr;
		if (!p)
		{
			*T = s;
		}
		else if(key < p->data)
		{
			p->lchild = s;
		}
		else
		{
			p->rchild = s;
		}
		return true;
	}
	return false;
}

bool CSearch::delete_data(BiTree* p)
{
	BiTree q, s;
	if ((*p)->rchild == NULL)  // 只有左子树
	{
		q = *p;
		*p = (*p)->lchild;
		delete q;
	}
	else if ((*p)->lchild == NULL)  // 只有右子树
	{
		q = *p;
		*p = (*p)->rchild;
		delete q;
	}
	else  // 左右子树都不为空
	{
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != *p)
		{
			q->rchild = s->lchild;
		}
		else
		{
			q->lchild = s->lchild;
		}
		delete s;
	}
	return false;
}

bool CSearch::delete_bst(BiTree* T, int key)
{
	if (!*T)
	{
		return false;
	}
	else
	{
		if (key == (*T)->data)
		{

		}
	}
}

//void CSearch::R_Rotate(BiTree1* p)
//{
//	BiTree1 L = (*p)->lchild;
//	(*p)->lchild = L->rchild;
//	(*p)->rchild = *p;
//}

void SearchTest::BinaryTest()
{
	int x[] = { 1,4,7,9,12,15,18,24,28,31,38,47,51,66,93 };
	int len = sizeof(x) / sizeof(int);
	CSearch search;
	int index = search.binary_search1(x, len, -12);
	cout << "-12 is: " << index << endl;
	index = search.binary_search1(x, len, 1);
	cout << "1 is: " << index << endl;
	index = search.binary_search1(x, len, 51);
	cout << "51 is: " << index << endl;
	index = search.binary_search1(x, len, 93);
	cout << "93 is: " << index << endl;
	index = search.binary_search1(x, len, 123);
	cout << "123 is: " << index << endl;
}

void SearchTest11()
{
	SearchTest tt;
	tt.BinaryTest(); 
}
