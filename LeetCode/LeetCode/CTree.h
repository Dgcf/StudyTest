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




private:
	TreeNode node_;
};

