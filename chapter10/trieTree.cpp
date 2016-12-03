#include <bits/stdc++.h>
using namespace std;

// implementation of trie structure
#define CHAR_SIZE 26
struct TrieNode
{
	TrieNode()
	{
		isLeaf = false;
		for (int i = 0; i < CHAR_SIZE; i++)
			children[i] = nullptr;
	}
	bool isLeaf;
	TrieNode* children[CHAR_SIZE];
};

void Insert(TrieNode* root, string word)
{
	TrieNode* cur = root;
	for (int i = 0; i < word.size(); i++)
	{
		if (cur->children[word[i] - 'a'] == nullptr)
		{
			cur->children[word[i]-'a'] = new TrieNode();
		}
		cur = cur->children[word[i]-'a'];
	}
	cur->isLeaf = true;
}
bool Search(TrieNode* root, string word)
{
	TrieNode* cur = root;
	for (int i = 0; i < word.size(); i++)
	{
		if (cur->children[word[i]-'a'] == nullptr) return false;
		cur = cur->children[word[i]-'a'];
	}
	return cur->isLeaf;
}

int main()
{
	TrieNode* root = new TrieNode();
	Insert(root, "jeremy");
	Insert(root, "doris");
	cout << "Searching for jerem" << endl;
	cout << "Result: " << Search(root, "jerem") << endl;
	return 0;
}
	

	

