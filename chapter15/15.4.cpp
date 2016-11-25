#include <bits/stdc++.h>

using namespace std;

// find LCA of a binary search tree

struct TreeNode
{
	int val;
	TreeNode* left, right;
};

// assume elements are distinct

TreeNode* FindLCA(TreeNode* root, TreeNode* s, TreeNode* b)
{
	// make sure s < b

	if (s->val > b->val) swap(s, b);

	TreeNode* p = root;
	
	while (p->val < s->val || p->val > b->val)
	{
		while (p->val < s->val)
			p = p->right;

		while (p->val > b->val)
			p = p->left;
	}

	return p;
}



