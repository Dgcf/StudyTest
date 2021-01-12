#pragma once

#include "common.h"

class spinlock
{
public:
	void Lock()
	{
		while (lock_.test_and_set());
	}

	void UnLock()
	{
		lock_.clear();
	}

private:
	std::atomic_flag lock_;
};

void spinlock_test(const string& s);

void multithread_spinlock();