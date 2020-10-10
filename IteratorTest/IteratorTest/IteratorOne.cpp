#include "IteratorOne.h"

void test_one()
{
    vector<int*> vecs;
    int* v0 = new int(0);
    vecs.push_back(v0);
    int* v1 = new int(1);
    vecs.push_back(v1);
    int* v2 = new int(2);
    vecs.push_back(v2);
    int* v3 = new int(3);
    vecs.push_back(v3);

    vector<int*>vecs1(vecs);

    for (vector<int*>::iterator it = vecs.begin(); it != vecs.end(); )
    {
        int* temp = *it;
        vecs.erase(it++);
        delete temp;
    }

    for (vector<int*>::iterator it = vecs1.begin(); it != vecs1.end(); ++it)
    {
        cout << **it << '\t';
    }
    cout << endl;
}

void test_two()
{
    list<char> l1 = { 'a','b','c','d','e','f','g' };
    list<char>::iterator iter = l1.begin();
    advance(iter, 4);
    cout << *iter << endl;
    iter = next(iter, -1);
    cout << *iter << endl;
}

void test_three(string s, int n, ...)
{
    va_list vl;
    string s123 = "good";
}

//string ABC::s1 = "good";

ABC::ABC()
{
}
