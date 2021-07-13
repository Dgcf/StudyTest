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

    // 超出时间限制
    int kthGrammar_My(int n, int k) {
        std::map<int, std::list<int>> m;
        int index = 1;
        m[index] = std::list<int>{ 0 };
        int num = n;
        while (--num)
        {
            std::list<int> tmp = m[index];
            std::list<int> mm;
            for (std::list<int>::iterator iter = tmp.begin(); iter != tmp.end(); ++iter)
            {
                if (*iter == 0)
                {
                    mm.push_back(0);
                    mm.push_back(1);
                }
                else if (1 == *iter)
                {
                    mm.push_back(1);
                    mm.push_back(0);
                }
            }
            m[++index] = mm;
        }
        std::list<int> r = m.at(n);
        int x = 1;
        for (std::list<int>::iterator iter = r.begin(); iter != r.end(); ++iter)
        {
            if (x++ == k)
            {
                return *iter;
            }
        }
        return -1;
    }

    // 1309
    string freqAlphabets(string s) {
        int len = s.size();
        string res, tmp;
        int i = 0, j = i + 2;
        for ( ;j < len; ++i, ++j)
        {
            if ('#' == s[j])
            {
                tmp = s.substr(i, j);
                char c = 'a' + std::stoi(tmp) - 1;
                res += c;
                i = j;
                j += 2;
            }
            else
            {
                char c = s[i] + 48;
                res += c;
            }
        }
        if (j >= len && i < len)
        {
            while (i<len)
            {
                char c = s[i++] + 48;
                res += c;
            }
        }


        /*string ans;
        for (int i = 0; i < s.size(); ++i) {
            if (i + 2 < s.size() && s[i + 2] == '#') {
                ans += char((s[i] - '0') * 10 + (s[i + 1] - '1') + 'a');
                i += 2;
            }
            else {
                ans += char(s[i] - '1' + 'a');
            }
       0 }
        return ans;*/

        return res;
    }

    string largestMerge(string word1, string word2) 
    {
        /*
        string s1 = "guguuuuuuuuuuuuuuguguuuuguug";
        string s2 = "gguggggggguuggguugggggg";
        string s3 = "guguuuuuuuuuuuuuuguguuuuguugguggggggguuggguuggggggg";
        string s2 = "guguuuuuuuuuuuuuuguguuuuguugguggggggguuggguuggggggg"
        string s4 = "guguuuuuuuuuuuuuuguguuuuguuggguggggggguuggguugggggg";
        string s5 = ""
        */

        int len1 = word1.size();
        int len2 = word2.size();
        string res;
        int i = 0, j = 0;
        while (i < len1 && j < len2)
        {
            if (word1[i] > word2[j])
            {
                res += word1[i++];
            }
            else if (word1[i] < word2[j])
            {
                res += word2[j++];
            }
            else
            {
                int x = i+1, y = j+1;
                while (1)
                {
                    if (x < len1 && y < len2)
                    {
                        if (word1[x] > word2[y])
                        {
                            res += word1[i++];
                            break;
                        }
                        else if (word1[x] < word2[y])
                        {
                            res += word2[j++];
                            break;
                        }
                        else
                        {
                            ++x; ++y;
                        }
                    }
                    else if (x < len1)
                    {
                        if (word1[x] > word2[y-1])
                        {
                            res += word1[i++];
                            break;
                        }
                        else if (word1[x] < word2[y-1])
                        {
                            res += word2[j++];
                            break;
                        }
                        else
                        {
                            ++x;
                        }
                    }
                    else if (y < len2)
                    {
                        if (word1[x - 1] > word2[y])
                        {
                            res += word1[i++];
                            break;
                        }
                        else if (word1[x - 1] < word2[y])
                        {
                            res += word2[j++];
                            break;
                        }
                        else
                        {
                            ++y;
                        }
                    }
                    else {
                        break;
                    }
                }
                if (x >= len1 && y >= len2)
                {
                    break;
                }
            }
        }
        string w1, w2;
        if (i < len1)
        {
            res += word1.substr(i);
        }
        if (j < len2)
        {
            res += word2.substr(j);
        }

        return res;
    }
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

inline void test3()
{
    Solution s;
    s.freqAlphabets(
        "10#11#12");
}

inline void test4()
{
    Solution s;
    /*string s1 = "guguuuuuuuuuuuuuuguguuuuguug";
    string s2 = "gguggggggguuggguugggggg";*/
    string s1 = "cabaa";
    string s2 = "bcaaa";
    string a = s.largestMerge(s1, s2);

    cout << a << endl;
}

