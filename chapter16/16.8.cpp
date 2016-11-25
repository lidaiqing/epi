#include <bits/stdc++.h>

using namespace std;


// generate all binary trees

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* Clone(TreeNode* root)
{
	if (root == nullptr) return nullptr;
	TreeNode* rootCopy = new TreeNode();
	rootCopy->val = root->val;
	rootCopy->left = Clone(root->left);
	rootCopy->right = Clone(root->right);
	return rootCopy;
}

vector<TreeNode*> GenerateAllTrees(int k)
{
	vector<TreeNode*> result;
	for (int i = 0; i < k - 1; i++)
	{
		int num_left = i;
		int num_right = k - i - 1;
		vector<TreeNode*> leftTree = GenerateAllTrees(num_left);
		vector<TreeNode*> rightTree = GenerateAllTrees(num_right);
		for (auto l : leftTree)
		{
			for (auto r: rightTree)
			{
				TreeNode* root = new TreeNode();
				root->left = Clone(l);
				root->right = Clone(r);
				result.emplace_back(root);
			}
		}
	}
	return result;
}

int main()
{
	vector<TreeNode*> result = GenerateAllTrees(10);
	return 0;
}
