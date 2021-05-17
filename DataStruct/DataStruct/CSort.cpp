#include "CSort.h"

int CSort::count_ = 0;

void CSort::swap(SqList* l, int i, int j)
{
	++count_;
	int temp = l->r[i];
	l->r[i] = l->r[j];
	l->r[j] = temp;
}

void CSort::BubleSort0(SqList s)
{
	// ·Ç
	for (size_t i = 0; i < s.length-1; i++)
	{
		for (size_t j = i+1; j < s.length; j++)
		{
			if (s.r[i] > s.r[j])
			{
				swap(&s, i, j);
			}
		}
	}
	cout << "compare count: " << count_ << endl;
	count_ = 0;
}

void CSort::BubleSort(SqList s)
{
	for (size_t i = 0; i < s.length-1; i++)
	{
		for (size_t j = s.length-1; j > i; j--)
		{
			if (s.r[j] < s.r[j - 1])
			{
				swap(&s, j, j-1);
			}
		}
	}
	cout << "compare count: " << count_ << endl;
	count_ = 0;
}

void CSort::SelectSort(SqList s)
{
	int index=0;
	for (size_t j = 0; j < s.length; j++)
	{
		index = j;

		for (size_t i = j+1; i < s.length; i++)
		{
			if (s.r[j] > s.r[i])
			{
				index = i;
			}
		}
		if (index != j)
		{
			swap(&s, j, index);
		}
	}
}

void CSort::InsertSort(SqList s)
{
	for (size_t i = 1; i < s.length; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (s.r[i] < s.r[j])
			{
				swap(&s, i, j);
			}
			/*else
			{
				break;
			}*/
		}
	}
	//int i, j;
	//for (i = 2; i <= s.length; i++)
	//{
	//	if (s.r[i] < s.r[i - 1])
	//	{
	//		s.r[0] = s.r[i]; // ÉèÖÃÉÚ±ø
	//		for (j = i - 1; s.r[j] > s.r[0]; j--)
	//		{
	//			s.r[j + 1] = s.r[j];
	//		}
	//		s.r[j + 1] = s.r[0];
	//	}
	//}
}

void CSort::ShellSort(SqList s)
{
	int i, j;
	int increment = s.length;
	do
	{
		increment = increment / 3 + 1;
		for (i = increment+1; i <= s.length; i++)
		{
			if (s.r[i] < s.r[i - increment])
			{
				s.r[0] = s.r[i];
				for (j = i - increment; j > 0 && s.r[0] < s.r[j]; j -= increment)
				{
					s.r[j + increment] = s.r[j];
				}
				s.r[j + increment] = s.r[0];
			}
		}
	} while (increment>1);
}

void CSort::HeapSort(SqList s)
{
	int i = 0;
	for (i = s.length / 2; i > 0; i--)
		HeapJust(&s, i, s.length);

	for (i = s.length; i > 1; i--)
	{
		swap(&s, 1, i);
		HeapJust(&s, 1, i-1);
	}
}

void CSort::MergeSort(SqList s)
{

}

void CSort::QuickSort(SqList s)
{
	QSort(&s, 0, s.length-1);
}

void CSort::HeapJust(SqList* L, int s, int m)
{
	int temp, j;
	temp = L->r[s];
	for (j = 2 * s; j <= m; j *= 2)                             
	{
		if (j < m && L->r[j] < L->r[j + 1])
		{
			++j;
		}
		if (temp >= L->r[j])
		{
			break;
		}
		L->r[s] = L->r[j];
		s = j;
	}
	L->r[s] = temp;
}

void CSort::MSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[10];
	if (s == t)
	{
		TR1[s] = SR[s];
	}
	else
	{
		m = (s + t) / 2;
		MSort(SR, TR2, s, m);
	}
}

void CSort::QSort(SqList* L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(L, low, high);
		QSort(L, low, pivot - 1);
		QSort(L, pivot + 1, high);
	}
}

int CSort::Partition(SqList* L, int low, int high)
{
	int pivotkey = L->r[low];
	while (low < high)
	{
		while (low < high && L->r[high] >= pivotkey)
		{
			high--;
		}
		swap(L, low, high);

		while (low < high && L->r[low] <= pivotkey)
		{
			low++;
		}
		swap(L, low, high);
	}

	return low;
}

int SortTest::randvalue()
{
	static std::uniform_int_distribution<int> d(1, 10000);
	static std::default_random_engine dre;

	return d(dre);
}

SqList SortTest::data(int l)
{
	SqList sq;
	memset(&sq, 0, sizeof(sq));
	sq.length = l;
	sq.r = new int[sq.length];
	for (size_t i = 0; i < sq.length; i++)
	{
		sq.r[i] = randvalue();
	}
	return sq;
}

void SortTest::print(SqList* p)
{
	for (size_t i = 0; i < p->length; i++)
	{
		cout << p->r[i] << " ";
	}
	cout << endl;
}

void SortTest::BubbleTest()
{
	SqList p = data(10000);
	//print(&p);
	sort_.BubleSort0(p);
	sort_.BubleSort(p);
	//print(&p);
	delete[] p.r;
}

void SortTest::SelectTest()
{
	SqList p = data(10);
	print(&p);
	sort_.SelectSort(p);
	print(&p);
	delete[] p.r;
}

void SortTest::InsertTest()
{
	SqList p = data(20);
	print(&p);
	sort_.InsertSort(p);
	print(&p);
	delete[] p.r;
}

void SortTest::ShellTest()
{
}

void SortTest::QuickTest()
{
	SqList p = data(20);
	print(&p);
	sort_.QuickSort(p);
	print(&p);
	delete[] p.r;
}
