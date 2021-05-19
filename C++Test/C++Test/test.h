#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


static int get_substr(const string& str, const string& sub)
{
	int m = str.size();
	int n = sub.size();
	int len = m - n;

	int index = -1;
	for (size_t i = 0; i <= len; i++)
	{
		int k = i;
		int sub_index = 0;
		while (str[k] == sub[sub_index] && sub_index < n)
		{
			++k;
			++sub_index;
		}
		if (sub_index == n)
		{
			return i;
		}
	}
	return index;
}

static void t4()
{
	int a = 0, b = 0;
	while (cin >> a)
	{
		cout << a << endl;
	}
}

static void get_in()
{
	string in;
	getline(std::cin, in);
	std::vector<size_t> vec_index;
	size_t index = in.find(" ");
	while (string::npos != index)
	{
		vec_index.push_back(std::stoi(in.substr(0, index)));
		in = in.substr(index + 1);
		index = in.find(" ");
	}
	vec_index.push_back(std::stoi(in));
}