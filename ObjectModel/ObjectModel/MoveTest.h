#pragma once

#include "common.h"

class MoveTest
{
};

inline void Test_move()
{
	int a = 12;
	int&& ar = std::move(a);
	cout << a << endl;
}

