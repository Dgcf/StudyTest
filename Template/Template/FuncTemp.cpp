#include "FuncTemp.h"

template<typename T>
void Test_header(const T& t)
{
	cout << "Enter in Test_header: " << t << endl;
}

void Test_FuncTemplate_0()
{
	Test_header("hello");
}
