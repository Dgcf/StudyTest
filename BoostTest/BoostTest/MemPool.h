#pragma once

#include "common.h"
#include "boost/pool/pool.hpp"

using namespace boost;
using namespace boost::details;

class MemPool
{
public:
	MemPool():
		pool_(8*sizeof(char))
	{

	}

	char* AllocChar(int size)
	{
		char* l = static_cast<char*>(pool_.ordered_malloc(size));
		strncpy(l, "1234567", static_cast<size_t>(size)*8);
		return l;
	}

	void FreeMem(void* const chunk)
	{
		pool_.ordered_free(chunk, 32);
	}
private:
	boost::pool<> pool_;
};


void test_Pool(int size);
