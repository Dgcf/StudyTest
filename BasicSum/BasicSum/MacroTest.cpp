#include "MacroTest.h"

#define TOSTR(str) #str

void Macro_ToStr()
{
	int iTest0 = 10;
	string strTest0;
	cout << TOSTR(iTest0) << endl;
	cout << TOSTR(strTest0) << endl;

	const char* is = "iTest0";
	const char* tmp = TOSTR(iTest0);
	int l = sizeof(tmp);
	int x = strncmp(is, tmp, l);
	if(x == 0)
	{
		cout << "== " << endl;
	}
	else
	{
		cout << "!= " << endl;
	}
}