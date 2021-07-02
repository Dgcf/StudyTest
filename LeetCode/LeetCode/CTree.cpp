#include "CTree.h"

vector<int> CTree::inorderTraversal(TreeNode* root)
{
    vector<int> v;
    InTraversal(root, v);
    return v;
}

vector<TreeNode*> CTree::generateTrees(int n)
{
    vector<TreeNode*> v;
    return v;
}

void CTree::InTraversal(TreeNode* node, vector<int>& v)
{
    // �ȷ������������ٷ��ʸ��ڵ㣬������������
    if (!node)
    {
        return;
    }
    
    InTraversal(node->left, v);
    v.push_back(node->val);
    InTraversal(node->right, v);
}

void CTree::InsertBST(int key)
{
    if (SearchKey(key, &node_))
    {
        return;
    }
    TreeNode* node = new TreeNode(key);
    Insert(node, &node_);
}

void CTree::Insert(TreeNode* node, TreeNode* src)
{
    // ���С������뵽���ӽڵ�
    if (node->val < src->val)
    {
        if (src->left)
        {
            Insert(node, src->left);
        }
        else
        {
            src->left = node;
        }
    }
    else if(node->val > src->val)
    {
        if (src->right)
        {
            Insert(node, src->right);
        }
        else
        {
            src->right = node;
        }
    }
    else 
    {
    }
}

bool CTree::SearchKey(int key, TreeNode* node)
{
    if (!node)
    {
        return false;
    }

    if (key < node->val)
    {
        SearchKey(key, node->left);
    }
    else if (key > node->val)
    {
        SearchKey(key, node->right);
    }
    else
    {
        return true;
    }
    return false;
}
