#include <bits/stdc++.h>
#include "linkedlist.h"

using namespace std;

Node* reverseList(Node* listHead, int start, int end)
{
	if (start == end) return NULL; // special case
	int k = 1;
	Node* dummyHead = new Node(0);
	dummyHead->next = listHead;
	Node* reverse_start = dummyHead;
	while (k < start)
	{
		reverse_start = reverse_start->next;
		k++;
	}

	Node* reverse_cur = reverse_start->next;
	while (start < end)
	{
		Node* temp = reverse_cur->next;
		reverse_cur->next = temp->next; // point to next reverse point
		temp->next = reverse_start->next;
		reverse_start->next = temp;
		start++;
	}

	return dummyHead->next;
}


int main()
{
	int a[] = {11, 3, 5, 7, 2};
	int n = 5;
	Node* listHead = LinkedList_builder(a, n);
	cout << "Testing list: ";
	printList(listHead);
	listHead = reverseList(listHead, 2, 4);
	cout << "Resulting list: ";
	printList(listHead);
	return 0;
}
