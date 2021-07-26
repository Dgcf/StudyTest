// C++Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "test.h"

#include <iostream>
#include <set>
using namespace std;


int getnums(const string& s)
{
    int max = 0, tmp = 0;
    bool flag = false;
    std::set<char> a = { 'a','e','i','o','u','A','E','I','O','U' };

    for (int i = 0; i < s.size(); i++)
    {
        if (a.find(s[i]) != a.end())
        {
            /*if (flag == false)
            {
                max = std::max(max, tmp);
                tmp = 0;
                ++tmp;
            }
            else {
                ++tmp;
            }
            flag = true;*/
            ++tmp;
        }
        else {
            //flag = false;
            max = std::max(max, tmp);
            tmp = 0;
        }
    }
    max = std::max(max, tmp);
    return max;
}

int main()
{
    string in = "asdbuiodevauufgh";
    string in1 = "a";
    //std::cin >> in;
    if (in1.size() == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << getnums(in1) << endl;
    }
    return 0;
}




