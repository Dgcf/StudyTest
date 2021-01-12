#include "AtomicTest.h"

void spinlock_test(const string &s)
{
	spinlock lock;
	lock.Lock();
	int index = 0;
	while (++index <= 10)
	{
		std::this_thread::sleep_for(std::chrono::seconds(2));
		printf("%s: good morning\n", s.c_str());
	}
	lock.UnLock();
}

void multithread_spinlock()
{
	std::future<void> res1 = std::async(spinlock_test, "mu");
	std::future<void> res2 = std::async(spinlock_test, "you");
	std::future<void> res3 = std::async(spinlock_test, "df");
	res1.get();
	res2.get();
	res3.get();
}
