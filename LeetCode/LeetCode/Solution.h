#pragma once
#include "commmon.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a = getValue(l1);
        int b = getValue(l2);
        int sum = a + b;
        ListNode* node = new ListNode;
        ListNode* head = node;
        int x = 0;
        while (sum)
        {
            node->val = sum % 10;
            sum = sum / 10;
            if (sum)
            {
                node->next = new ListNode;
                node = node->next;
            }
        }
        return head;
    }

    void getNums(ListNode* pNode, int& b, int& s)
    {
        if (!pNode)
        {
            return;
        }
        b *= 10;
        getNums(pNode->next, b, s);
        b /= 10;
        s += (b * pNode->val);
        
    }

    int getValue(ListNode* node)
    {
        int b = 1, s = 0;
        getNums(node, b, s);
        return s;
    }

    int lengthOfLongestSubstring(string s) {
        map<size_t, vector<char>> m;
        for (size_t index = 0; index < s.size(); index++)
        {
            vector<char> v;
            v.push_back(s[index]);
            bool c = false;
            for (size_t y = index+1; y < s.size(); y++)
            {
                for (size_t i = 0; i < v.size(); i++)
                {
                    if (s[y] == v[i])
                    {
                        c = true;
                        break;
                    }
                }
                if (c)
                {
                    break;
                }
                v.push_back(s[y]);
            }
            m.insert({ index, v });
        }
        int max = 0;
        int index = -1;
        for (map<size_t, vector<char>>::iterator iter = m.begin(); iter != m.end(); ++iter)
        {
            if (max < iter->second.size())
            {
                max = iter->second.size();
                index = iter->first;
            }
        }
        return max;
    }

    // 好的解法
    int lengthOfLongestSubstring1(string s)
    {
        unordered_set<char> occ;
        int n = s.size();
        int rk = -1, ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
            {
                occ.erase(s[i - 1]);
            }
            while (rk+1<n && !occ.count(s[rk+1]))
            {
                occ.insert(s[rk + 1]);
                ++rk;
            }
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }

    // 5
    string longestPalindrome(string s) 
    { 
        int max=0;
        vector<string> m;
        string r;
        int n = s.size();
        for (size_t i = 0; i < n; ++i)
        {
            string s0, s1, sr;
            for (size_t j = 0; i+j < n; ++j)
            {
                s0 = s0 + s[i+j];
                s1 = s[i+j] + s1;
                if (s0 == s1)
                {
                    m.push_back(s0);
                }
            }
        }
        for (vector<string>::iterator iter = m.begin(); iter != m.end(); ++iter)
        {
            if (max < iter->size())
            {
                max = iter->size();
                r = *iter;
            }
        }
        return r;
    }

    string convert(string s, int numRows) 
    {
        vector<vector<char>> t;
        vector<char>* pData = new vector<char>[numRows];
        int index = 0;
        int len = s.size();
        while (index<len)
        {
            for (int i = 0; i < numRows; i++)
            {
                char c = s[index];
                pData[i].push_back(c);
                if (++index >= len)
                {
                    goto end;
                }
            }
            for (int j = numRows - 2; j > 0; j--)
            {
                pData[j].push_back(s[index]);
                if (++index >= len)
                {
                    goto end;
                }
            }
        }
    end:
        string res;
        int d = -1;
        vector<char> vec;
        while (++d<numRows)
        {
            int size = pData[d].size();
            for (int x = 0; x < size; ++x)
            {
                vec.push_back(pData[d].at(x));
            }
        }

        delete[] pData;
        char* p = new char[len+1];
        p[len] = '\0';
        memset(p, 0, len);
        for (int l = 0; l < len; ++l)
        {
            p[l] = vec.at(l);
        }
        res = p;
        delete[] p;
        return res;
    }

    void getReverse(int x, int& d, int m)
    {
        if (x / 10 == 0)
        {
            return;
        }
        int i = x % 10;
        if (i)
        {
            d *= 10;
            m += d * i;
        }
        
        
    }

/*
请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

函数 myAtoi(string s) 的算法如下：

读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
返回整数作为最终结果。
注意：

本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
*/
};

inline void test()
{
    ListNode* node1 = new ListNode(2, new ListNode(4, new ListNode(9)));
    ListNode* node2 = new ListNode(5, new ListNode(6, new ListNode(4, new ListNode(9))));
    Solution s;
    ListNode* node3 = s.addTwoNumbers(node1, node2);
    ListNode* tmp = node3;
    while (tmp)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

inline void test1()
{
    Solution s;
    string s1 = "abcabcbb";
    string s2 = "pwwkew";
    int len = s.lengthOfLongestSubstring(s2);
    cout << "len is: " << len << endl;
}

inline void test2()
{
    Solution s;
    string ss = s.convert("PAYPALISHIRING", 3);
    cout << ss.size() << endl;
}

