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
};

