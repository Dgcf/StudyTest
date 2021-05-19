// C++Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "test.h"

std::vector<int> get_point()
{
	string in;
	getline(std::cin, in);
	std::vector<int> vec_index;
	size_t index = in.find(" ");
	while (string::npos != index)
	{
		vec_index.push_back(stoi(in.substr(0, index)));
		in = in.substr(index + 1);
		index = in.find(" ");
	}
	vec_index.push_back(stoi(in.substr(0, index)));
	int point = -1;
	int num = vec_index.at(0)*2;
	while (cin>>point)
	{
		vec_index.push_back(point);
		if (--num==0)
		{
			break;
		}
	}
	return vec_index;
}

int get_num()
{
	std::vector<int> point = get_point();
	// 奇数index为x坐标，偶数index为y坐标
	int j = 3;
	int o = 4;
	int size = point.size();
	int air_x = point.at(1);
	int air_y = point.at(2);
	std::vector<int> v;
	std::map<int, int> m;
	int total = 0;
	while (o < size && j < size)
	{
		// 机场在x轴,y坐标为0
		if (!air_y && air_x)
		{
			if (point.at(o++) == 0)
			{
				++total;
			}
		}
		else if(!air_x && air_y) // 机场在y轴,x坐标为0
		{
			if (point.at(j++) = 0)
			{
				++total;
			}
		}
		else
		{
			int x = point.at(o++) - air_y;
			int y = point.at(j++) - air_x;
			// 机场在其他
			int z = y / x;
			++m[z];
		}
	}

	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		int val1 = it->second;
		if (total < val1)
		{
			total = val1;
		}
	}
	return total-1;
}

int main()
{
	int n = get_num();
	cout << n << endl;
}


