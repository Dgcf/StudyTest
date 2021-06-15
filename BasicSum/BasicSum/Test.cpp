#include "Test.h"

string test_str0 = "hello";
string test_str1 = "world";
int test_int0 = 12;
int test_int1 = 13;
int test_int0test_int1 = 34;
int g_iTest = 67;
extern const int g_ciTest0 = 13;


void build_macro()
{
	cout << __LINE__ << endl;
	cout << __FILE__ << endl;
	cout << __DATE__ << endl;
	cout << __TIME__ << endl;
	cout << __func__ << endl;
}

void test_jin()
{
	TEST0(test_str0);
	TEST0(test_int0);
	int s = TEST2(test_int0, test_int1);
	cout << s << endl;
}

void test_build_macro()
{
	build_macro();
}

void test_const_str()
{
	const char s[] = "hello";
	cout << sizeof(s) << endl;
	cout << strlen(s) << endl;
}

void test_const_non(string s)
{
	cout << s << endl;
}

void test_const_non0()
{
	const string s = "hl";
	test_const_non("good");
}

void test_align_0()
{
	HowManyBytes ma;
	cout << "sizeof(ma): " << sizeof(ma) << endl;
	cout << "offsetof(ma, a): " << offsetof(HowManyBytes, a) << endl;
	cout << "offsetof(ma, b): " << offsetof(HowManyBytes, b) << endl;
}

void test_alignof_0()
{
	cout << alignof(HowManyBytes) << endl;
	cout << sizeof(STR1) << endl;
	int a = 0;
}

void test_alignas_0()
{
	cout << sizeof(STR2) << endl;
	cout << alignof(std::max_align_t) << endl;
}

void test_static_var()
{
	cout << ++g_stI << endl;
	cout << ++g_iTest << endl;
	cout << g_ciTest0 << endl;
}



void test_pragmapack_0()
{
	//cout << "sizeof(STR1): " << sizeof(STR1) << "; alignof(STR1): " << alignof(STR1) << endl;
	//cout << "sizeof(STR2): " << sizeof(STR2) << "; alignof(STR2): " << alignof(STR2) << endl;
	//simulate();
}

void test_basic1()
{
	/*unsigned u = 10;
	int i = -42;
	cout << u + i << endl;*/
	int a = 10;
	printf("%d, %x, %o", a, a, a);
}
