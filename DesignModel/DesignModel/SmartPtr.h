#pragma once
#include "common.h"


template<typename T>
struct NoChecking
{
	static void Check(T*) {}
};