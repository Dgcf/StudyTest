#pragma once

#include "commmon.h"


class TwentyTraining
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int left = 0, right = nums.size() - 1;
        int index = 0;
        while (left <= right)
        {
            index = left + (right - left) / 2;
            if (nums[index] > target)
            {
                right = index - 1;
            }
            else if(nums[index] < target)
            { 
                left = index + 1;
            }
            else
            {
                break;
            }
        }
        if (nums[index] != target)
        {
            ++index;
        }
        return index;
    }

    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int m = 0;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (target == nums[m])
            {
                 return m;
            }
            else if (target > nums[m])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return -1;
    }

// 2
/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
示例 1：
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]

示例 2：
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
*/
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int> v;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
        {
            v.push_back(*iter * *iter);
        }

        std::sort(nums.begin(), nums.end());
    }

/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
进阶：
尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
 
示例 1:
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]

示例 2:
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释:
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
*/
    void rotate(vector<int>& nums, int k) 
    {
        vector<int> v;
        int len = nums.size();
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i + k >= len)
            {
                v.push_back(nums[i + k - len]);
            }
            else {
                v.push_back(nums[len - k + i]);
            }

        }
        nums = v;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return { it->second, i };
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int m = 0, n = 0, sum = 0;
        ListNode* node = nullptr;
        ListNode* res = nullptr;
        while (true)
        {
            int sum = 0;
            if (l1)
            {
                sum = l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += m;
            m = sum / 10;
            n = sum % 10;
            if (node)
            {
                node->val = n;
            }
            else
            {
                node = new ListNode(n);
                res = node;
            }
            if (!l1 && !l2 && m==0)
            {
                return res;
            }
            node->next = new ListNode;
            node = node->next;
        }
        return res;
    }

    int getNums(ListNode* l)
    {
        int v = 1, res = 0;
        while (l)
        {
            res += l->val * v;
            v *= 10;
            l = l->next;
        }
        return res;
    }

    ListNode* getRes(int num)
    {
        ListNode* node;
        if (0 == num)
        {
            node = new ListNode(0);
            return node;
        }
        node = new ListNode;
        ListNode* temp = node;
        while (num)
        {
            node->val = num % 10;
            cout << node->val << endl;
            num = num / 10;
            if (num)
            {
                node->next = new ListNode;
                node = node->next;
            }
        }

       // ListNode* s= *temp;
        return temp;
    }

    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow = head, *fast = head;
        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* l = head, * r = head, * pre = head;

        while (r && n--)
        {
            r = r->next;
        }
        if (!r)
        {
            if (head->next)
            {
                head = head->next;
                delete pre;
                pre = nullptr;
            }
            else
            {
                delete head;
                head = nullptr;
            }
            return head;
        }

        while (r)
        {
            pre = l;
            l = l->next;
            r = r->next;
        }
        pre->next = l->next;
        delete l;
        l = nullptr;
        return head;

    }

    int lengthOfLongestSubstring(string s) 
    {
        int size = s.size();
        if (size < 2)
        {
            return size;
        }
        int l = 0, r = 0, res = 0;
        unordered_set<char> st;

        while (r < size)
        {
            while (!st.insert(s[r]).second)
            {
                res = (res > st.size()) ? res : st.size();
                st.erase(s[l++]);
            }
            ++r;
        }
        res = (res > st.size()) ? res : st.size();
        return res;
    }

    void print(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        cout << "temp: " << root->val << endl;
        print(root->left);
        print(root->right);
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        TreeNode* node;
        node = addTree(root1, root2, node);
        TreeNode* temp = node;
        print(temp);

        return node;
    }

    TreeNode* addTree(TreeNode* root1, TreeNode* root2, TreeNode* &node)
    {
        if (!root1 && !root2)
        {
            return nullptr;
        }
        node = new TreeNode;
        TreeNode* left1 = nullptr, *right1 = nullptr;
        TreeNode* left2 = nullptr, *right2 = nullptr;

        if (root1)
        {
            node->val += root1->val;
            left1 = root1->left;
            right1 = root1->right;
        }
        if (root2)
        {
            node->val += root2->val;
            left2 = root2->left;
            right2 = root2->right;
        }
        cout << node->val << endl;
        addTree(left1, left2, node->left);
        addTree(right1, right2, node->right);
        return node;
    }

    Node* connect(Node* root) 
    {
        if (!root)
        {
            return root;
        }
        Node* res = root;
        NodeConnect(root->left, root->right);
        return res;
    }

    void NodeConnect(Node* l, Node* r)
    {
        if (!l)
        {
            return ;
        }
        
        l->next = r;
        NodeConnect(l->left, l->right);
        NodeConnect(l->right, r->left);
        NodeConnect(r->left, r->right);
    }

    // 
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) 
            return nullptr;
        ListNode* node = new ListNode;
        ListNode* tmp = node;
        while (l1 || l2)
        {
            if (!l1)
            {
                tmp->val = l2->val;
                l2 = l2->next;
            }
            else if (!l2)
            {
                tmp->val = l1->val;
                l1 = l1->next;
            }
            else
            {
                if (l1->val >= l2->val)
                {
                    tmp->val = l2->val;
                    l2 = l2->next;
                }
                else if(l1->val < l2->val)
                {
                    tmp->val = l1->val;
                    l1 = l1->next;
                }
            }
            if (l1 || l2)
            {
                tmp->next = new ListNode;
                tmp = tmp->next;
            }
        }
        return node;
    }

    // 反转链表
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode* tmp = head->next->next;
        if (!tmp)
        {
            head->next->next = head;
            return head->next;
        }

        ListNode* node = head->next;
        while (tmp)
        {
            node->next = head;
            head = node;
            node = tmp;
            tmp = tmp->next;
        }
        node->next = head;
        return node;
    }

    // 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
    vector<vector<int>> combine(int n, int k)
    {
        int size = n - 1;
        int s = n - k;
        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        backtrack(v, nums);
        return vec;
    }

    void backtrack(vector<int>& v, vector<int>& nums)
    {
        if (v.size() == nums.size())
        {
            vec.push_back(v);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (v.end() != std::find(v.begin(), v.end(), nums.at(i)))
            {
                continue;
            }
            v.push_back(nums.at(i));
            backtrack(v, nums);
            v.pop_back();
        }
    }

    vector<vector<int>> vec;

    void backtrack(vector<int>& v, int nums, int k, int start)
    {
        if (v.size() == k)
        {
            vec.push_back(v);
            return;
        }

        for (int i = start; i <= nums; ++i)
        {
            if (v.end() != std::find(v.begin(), v.end(), i))
            {
                continue;
            }
            v.push_back(i);
            backtrack(v, nums, k, i);
            v.pop_back();
        }
    }
   
};

