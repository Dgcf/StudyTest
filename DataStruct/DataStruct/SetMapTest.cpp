#include "SetMapTest.h"

void set_test_create0()
{
	// 以两种方式定义排序准则
	std::set<int> coll = { 7,3,0,5,1,8,4,2,15 };
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	std::set<int, greater<int>> coll1 = { 7,3,0,6,5,1,8,4,12,9,2,15 };
	
	
	cout << coll.size() << endl;
	cout << coll.max_size() << endl;
	cout << coll1.size() << endl;
	cout << coll1.max_size() << endl;

	cout << "distance: " << std::distance(coll1.begin(), coll1.find(8)) << endl;
	std::pair<set<int,greater<int>>::iterator,bool> s = coll1.insert(8);
	copy(coll1.begin(), coll1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	if (s.second)
	{
		cout << "pair distance: " << distance(coll1.begin(), s.first) << endl;
	}
	else
	{
		cout << "insert fail" << endl;
	}

	cout << "elem print: " << endl;
	for (int elem : coll1)
	{
		cout << elem << " ";
	}
	cout << endl;
}

void set_test_create1()
{
	// 以构造函数参数定义
}

void map_test_create0()
{
	std::map<int, string> map0 = {
		std::pair<int, string>(12,"hi"),
		std::pair<int, string>(8, "morning"),
		std::pair<int, string>(3, "money"),
		std::pair<int, string>(9, "this"),
		std::pair<int, string>(6, "how"),
		std::pair<int, string>(15, "big"),
		std::pair<int, string>(7, "shide")
	};

	for_each(map0.begin(), map0.end(), [](std::pair<int, string> it) {
		cout << it.second << " ";
		});
	cout << endl;
	cout << "size: " << map0.size() << "  max_size: " << map0.max_size() << endl;

	std::map<int, string> map1 = map0;
	map<int, string>::iterator iter = map0.find(9);
	cout << "find, first: " << iter->first << " second: " << iter->second << endl;

	// 三种方式插入map：
	std::map<int, string> map2;
	map2.insert(std::map<int, string>::value_type(14, "hundsun"));
	map2.insert(std::map<int, string>::value_type(2, "hello"));

	map2.insert(std::pair<int, string>(5, "good"));
	map2.insert(std::pair<int, string>(12, "are"));

	map2.insert(std::make_pair<int, string>(8, "make"));
	std::pair<map<int, string>::iterator, bool> i = map2.insert(std::make_pair<int, string>(6, "pair"));

	if (i.second)
	{
		cout << "insert success" << endl;
		for_each(map2.begin(), map2.end(), [](std::pair<const int, string>& it) {
			cout << "first: " << it.first << "  second: " << it.second << endl;
			});
	}
	else
	{
		cout << "insert fail" << endl;
	}
	
}
