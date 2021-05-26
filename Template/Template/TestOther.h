#pragma once

void TestFunction();

template<typename Y>
void test_a();

template<typename T>
class TestOther
{
public:
	te
	TestOther(const T& t) :
		t_(t)
	{}

private:
	T t_;
};

void test_other();

template<typename Y>
inline void test_a()
{
}
