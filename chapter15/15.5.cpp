#include <bits/stdc++.h>

using namespace std;

// rebuild BST from preorder traversal

struct TreeNode {
	int val;
	TreeNode* left, right;
};

TreeNode* RebuiltBSTHelper(const vector<int>& preorder, int lower_bound, int upper_bound, int& root_idx)
{
	if (root_idx == preorder.size()) return NULL; // reach the end of array

	int root = preorder[root_idx];

	if (root < lower_bound || root > upper_bound) return NULL; // out of bound
	root_idx++;

	TreeNode* left = RebuiltBSTHelper(preorder, lower_bound, root, root_idx);
	TreeNode* right = RebuiltBSTHelper(preorder, root, upper_bound, root_idx);

	TreeNode* root_node = new TreeNode();
	root_node->val = root;
	root_node->left = left;
	root_node->right = right;
	return root_node;
}

TreeNode* RebuiltBST(const vector<int>& preorder)
{
	int root_idx = 0;
	return RebuiltBSTHelper(preorder, INT_MIN, INT_MAX, root_idx);
}	
