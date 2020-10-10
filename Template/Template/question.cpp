#include "question.h"

void test_wk_0()
{
	//unsigned int a = 10;
	long a = 10;
	char b[32];
	strncpy(b, "hello", sizeof("hello"));
	const char* c = "food";
	double d = 12.34;
	char e = 'a';

	wk_0(a);
	wk_0(b);
	wk_0(c);
	wk_0(d);
}

void test_print()
{
	long a = 10;
	char b[32];
	strncpy(b, "hello", sizeof("hello"));
	const char* c = "food";
	double d = 12.34;
	char e = 'a';
	print0(a);
	print0(b);
	print0(c);
	print0(d);
	print0(e);
}
