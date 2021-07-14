#pragma once
#include "commmon.h"


 struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class CTree
{
public:
	// 
	vector<int> inorderTraversal(TreeNode* root);

	// 
	vector<TreeNode*> generateTrees(int n);

private:
	void InTraversal(TreeNode* node, vector<int>& v);

	// 向二叉查找树中插入数据
	void InsertBST(int key);
	// 插入
	void Insert(TreeNode* node, TreeNode* src);

	// 搜索
	bool SearchKey(int key, TreeNode* node);

	// leetcode 129
	int sumNumbers(TreeNode* root) 
	{
		return dfs(root, 0);
	}

	int dfs(TreeNode* root, int prevSum)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int sum = prevSum * 10 + root->val;
		if (root->left == nullptr && root->right == nullptr)
		{
			return sum;
		}
		else
		{
			return dfs(root->left, sum) + dfs(root->right, sum);
		}
	}

	vector<TreeNode*> generateTrees(int start, int end) {
		if (start > end) {
			return { nullptr };
		}
		vector<TreeNode*> allTrees;
		// 枚举可行根节点
		for (int i = start; i <= end; i++) {
			// 获得所有可行的左子树集合
			vector<TreeNode*> leftTrees = generateTrees(start, i - 1);

			// 获得所有可行的右子树集合
			vector<TreeNode*> rightTrees = generateTrees(i + 1, end);

			// 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
			for (auto& left : leftTrees) {
				for (auto& right : rightTrees) {
					TreeNode* currTree = new TreeNode(i);
					currTree->left = left;
					currTree->right = right;
					allTrees.emplace_back(currTree);
				}
			}
		}
		return allTrees;
	}

	bool valid(TreeNode* root, int n)
	{
		if (!root)
		{
			return true;
		}
		if (n < root->val)
		{
			return false;
		}
		if (!valid(root->left, n))
		{
			return false;
		}
		valid(root->right, n);
	}

public:
	vector<TreeNode*> generateTree(int n) {
		if (!n) {
			return {};
		}
		return generateTrees(1, n);
	}


private:
	TreeNode node_;
};

