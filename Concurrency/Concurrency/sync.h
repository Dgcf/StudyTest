#pragma once
#include "common.h"

std::mutex mut;
std::queue<int> data_queue;
std::condition_variable data_cond;

void data_preparation_thread()
{
	while (1)
	{

	}
}