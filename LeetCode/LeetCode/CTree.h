#pragma once
#include "commmon.h"



class CTree
{
public:
	// 
	vector<int> inorderTraversal(TreeNode* root);

	int abc(TreeNode* root, int val)
	{
		if (!root)
		{
			return 0;
		}
		if (val == root->val)
		{
			return 1;
		}
		return abc(root->left, val) || abc(root->right, val);
	}

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

	// 反转二叉树
	TreeNode* invertTree(TreeNode* root) {
		if (!root)
		{
			return nullptr;
		}
		TreeNode* tmp = root->left;
		if(root->left) root->left = root->right;
		if(root->right) root->right = tmp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}

	Node* connect(Node* root) {
		if (!root)
		{
			return nullptr;
		}
		ConnectTwoNode(root->left, root->right);
		return root;
	}

	void ConnectTwoNode(Node* node1, Node* node2)
	{
		if (!node1 || !node2)
		{
			return;
		}

		node1->next = node2;
		ConnectTwoNode(node1->left, node1->right);
		ConnectTwoNode(node2->left, node2->right);
		ConnectTwoNode(node1->right, node2->left);
	}


	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

	}

	void binary(vector<int>& v, vector<int>::iterator& it)
	{
		if (v.empty())
		{
			return;
		}
		int key = v.at(0);
		for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			if (key > *iter)
			{
				key = *iter;
				it = iter;
			}
		}
	}

	void flatten(TreeNode* root)
	{
		ge(root);
	}

	TreeNode* ge(TreeNode* root)
	{
		if (!root) { return nullptr; }
		ge(root->left);
		ge(root->right);

		TreeNode* node = root->right;
		root->right = root->left;
		root->right->right = node;
		
		return node;
	}

	void st(TreeNode* root)
	{
		if (!root)
		{
			return;
		}

		TreeNode* node = root->right;
		root->right = ge(root->left);
		root->right->right = node;
	}


	Node* connect1(Node* root) {
		if (!root)
		{
			return NULL;
		}
		root->next = NULL;
		cc(root->left, root->right);
	}

	void cc(Node* l, Node* r)
	{
		if (!l && !r) return;
		
		l->next = r;
		cc(l->left, l->right);
		cc(l->right, r->left);
		cc(r->left, r->right);
	}


private:
	TreeNode node_;
};

