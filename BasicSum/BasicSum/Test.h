#pragma once

#include "common.h"

static int g_stI = 12;
extern int g_iTest;
//extern const int g_ciTest0;

#if __cplusplus > 201103L
#error "hello"
#endif

/**********************
‘§±‡“Î£¨±‡“Î≤‚ ‘
**********************/
void build_macro();

#define TEST0(n) printf(#n"\n")
#define TEST1(a,b,c,d) a##b##c##d
#define TEST2(a,b) a##b

void test_jin();

void test_build_macro();

/***********************
≤‚ ‘≥£¡ø
***********************/
void test_const_str();
void test_const_non(string s);
void test_const_non0();

/**********************
≤‚ ‘∂‘∆Î
**********************/
struct HowManyBytes
{
	char a;
	int b;
};

void test_align_0();

struct alignas(32) ColorVector
{
	double r;
	double g;
	double b;
	double a;
};

struct alignas(8) ColorVector1
{
	int r;
	char g;
	char a;
	int b;
};


#pragma pack(push)
#pragma pack(4)
struct STR1
{
	char m1;
	double m4;
	int m3;
};
#pragma pack(pop)


struct STR2
{
	char c1;
	double d2;
	int i3;
	double d4;			//40+16  24+16
	ColorVector1 c6;
};

void test_alignof_0();

void test_static_var();

void test_alignas_0();

void test_pragmapack_0();

void test_basic1();

//#pragma pack(show)

class ABC1
{
public:
	void open()
	{
		cout << "111" << endl;
	}

	ABC1() = default;

	ABC1(const ABC1& a) = delete;
	/*{
		cout << "copy" << endl;
	}*/
};

void test_bind_abc();

void test_forward();