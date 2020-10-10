#pragma once

#include "common.h"

string* MallocStr(const string& s)
{
    return new string(s);
}


class AT
{
public:
    template<typename T1, typename T2>
    auto NewObj(T1& t1, T2& t2) -> typename T1::mapped_type
    {
        typename T1::mapped_type ptr = NULL;
        uint32_t uRecordCount = 0;
        int32_t iErrorNo = 0;

        if (t1.find(t2) != t1.end())
        {
            ptr = t1.at(t2);
        }
        else
        {
            ptr = MallocStr("I am new");
            t1.insert({ t2, ptr });
        }
        return ptr;
    }

    template<typename _Tp>
    auto GetObj(const _Tp& tp, int id) const -> typename _Tp::mapped_type
    {
        typename _Tp::mapped_type ptr = NULL;
        if (tp.find(id) != tp.end())
        {
            ptr = tp.at(id);
        }
        return ptr;
    }
};


void returntest()
{
    int x = 0;
    map<int, string*> map1;
    
    map1.insert({ 0, MallocStr("hello") });
    map1.insert({ 2, MallocStr("good") });
    map1.insert({ 4, MallocStr("morning") });

    AT at;
    string* s = at.NewObj(map1, x);
    cout << *s << endl;
    x = 10;
    string* s1 = at.NewObj(map1, x);
    cout << *s1 << endl;
    x = 4;
    string* s2 = at.NewObj(map1, x);
    cout << *s2 << endl;
    x = 1;
    string* s3 = at.NewObj(map1, x);
    cout << *s3 << endl;

    string* s4 = at.GetObj(map1, 0);
    cout << *s4 << endl;
    string* s5 = at.GetObj(map1, 2);
    cout << *s5 << endl;
    string* s6 = at.GetObj(map1, 4);
    cout << *s6 << endl;
}
