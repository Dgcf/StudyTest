#pragma once

#include "common.h"

class MoveTest
{
};

inline void Test_move()
{
	int a = 12;
	int&& ar = std::move(a);
	cout << a << endl;
}


class FileOp1
{
public:
    FileOp1(int x) :fp_(nullptr), OpenTries_(x)
    {
    }

    FileOp1(const FileOp1&)
    {
        cout << "copy construct" << endl;
    }

    FileOp1(const FileOp1&&)
    {
        cout << "move construct" << endl;
    }

    ~FileOp1()
    {
        cout << "end" << endl;
    }

    int get()
    {
        return OpenTries_;
    }
public:
    FILE* fp_;
    int32_t OpenTries_;
};

static void test222()
{
    vector<FileOp1> vFileop;
    FileOp1 s(1);
    vFileop.push_back(s);
    FileOp1 s2(2);
    vFileop.emplace_back(s);

    cout << s.get() << endl;
    int x = 10;
}

