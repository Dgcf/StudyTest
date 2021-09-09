#pragma once
#include "common.h"

void doSomething(std::promise<std::string>& p)
{
	try
	{

	}
	catch (const std::exception&)
	{
		p.set_exception(std::current_exception());
	}
}

void test_promise()
{
	try
	{
		std::promise<std::string> p;
		std::thread t(doSomething, std::ref(p));
		t.detach();

		std::future<std::string> f(p.get_future());
	}
	catch (const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << std::endl;
	}
	
}

