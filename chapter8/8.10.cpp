#include <bits/stdc++.h>
#include "linkedlist.h"

using namespace std;

Node* evenAndOdd(Node* listHead)
{
	Node* evenListHead = NULL;
	Node* oddListHead = NULL;
	Node* evenListTail = NULL;
	Node* oddListTail = NULL;
	if (listHead == NULL) return NULL;
	int turn = 0;
	Node* cur = listHead;
	while (cur)
	{
		Node* next = cur->next;
		cur->next = NULL;
		if (turn == 0)
		{
			if (evenListHead == NULL)
			{
				evenListHead = cur;
				evenListTail = cur;
			} else {
				evenListTail->next = cur;
				evenListTail = cur;
			}
			turn = 1 - turn;
		} else {
			if (oddListHead == NULL)
			{
				oddListHead = cur;
				oddListTail = cur;
			} else {
				oddListTail->next = cur;
				oddListTail = cur;
			}
			turn = 1 - turn;
		}
		cur = next;
	}
	evenListTail->next = oddListHead;
	return evenListHead;
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9};
	int n = 9;

	
	Node* listHead = LinkedList_builder(a, n);
	cout << "Testing list: ";
	printList(listHead);
	listHead = evenAndOdd(listHead);
	cout << "Resulting list: ";
	printList(listHead);
	return 0;
}
