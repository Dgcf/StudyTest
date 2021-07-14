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

	// �����������в�������
	void InsertBST(int key);
	// ����
	void Insert(TreeNode* node, TreeNode* src);

	// ����
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
		// ö�ٿ��и��ڵ�
		for (int i = start; i <= end; i++) {
			// ������п��е�����������
			vector<TreeNode*> leftTrees = generateTrees(start, i - 1);

			// ������п��е�����������
			vector<TreeNode*> rightTrees = generateTrees(i + 1, end);

			// ��������������ѡ��һ������������������������ѡ��һ����������ƴ�ӵ����ڵ���
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

