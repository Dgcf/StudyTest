#include "MemPool.h"

void test_Pool(int size)
{
	MemPool p;
	
	char* s1 = p.AllocChar(1);
	char* s2 = p.AllocChar(4);
	char* s3 = p.AllocChar(1);
	char* s4 = p.AllocChar(8);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	p.FreeMem(s1);
	char* s5 = p.AllocChar(1);
	p.FreeMem(s5);
	char* s6 = p.AllocChar(2);

}
