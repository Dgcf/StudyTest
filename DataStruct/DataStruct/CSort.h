#pragma once
#include<stdlib.h>
#include <string.h>
#include <random>
#include <iostream>
using namespace std;

#define MAXSIZE 10

typedef struct
{
	int* r;
	int length;
}SqList;


class CSort
{
public:
	static void swap(SqList* l, int i, int j);
	

	// √∞≈›≈≈–Ú,¥”–°µΩ¥Û
	void BubleSort0(SqList s);
	void BubleSort(SqList s);

	// —°‘Ò
	void SelectSort(SqList s);

	// ≤Â»Î
	void InsertSort(SqList s);

	// œ£∂˚≈≈–Ú
	void ShellSort(SqList s);

	// ∂—≈≈–Ú
	void HeapSort(SqList s);

	// πÈ≤¢≈≈–Ú
	void MergeSort(SqList s);

	// øÏÀŸ≈≈–Ú
	void QuickSort(SqList s);


private:
	void HeapJust(SqList* L, int s, int m);
	void MSort(int SR[], int TR1[], int s, int t);
	void QSort(SqList* L, int low, int high);
	int Partition(SqList* L, int low, int high);

private:
	static int count_;
};


class SortTest
{
public:
	SortTest() = default;
	~SortTest() = default;
	static int randvalue();
	SqList data(int l);
	void print(SqList* p);

	void BubbleTest();
	void SelectTest();
	void InsertTest();

	void ShellTest();
	void QuickTest();
private:
	CSort sort_;
};
	