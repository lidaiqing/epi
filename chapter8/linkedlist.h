#include <bits/stdc++.h>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int _val) : val(_val), next(NULL) {}
};

Node* LinkedList_builder(int a[], int n)
{
	Node* head = new Node(a[0]);
	Node* cur = head;
	int i = 1;
	while (i < n)
	{
		Node* newNode = new Node(a[i++]);
		cur->next = newNode;
		cur = cur->next;
	}
	return head;
}

void printList(Node* head)
{
	Node* cur = head;
	while (cur)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

