#include <bits/stdc++.h>

using namespace std;

// finding the position of key in a cyclically sorted array with distinct elements

int findElement(int a[], int n, int key)
{
	int left = 0, right = n-1;
	while (left <= right)
	{
		int m = left + (right - left) / 2;
		if (key == a[m]) return m;
		else if (key > a[m])
		{
			if (key <= a[right]) left = m + 1;
			else right = m - 1;
		}
		else
		{
			if (key >= a[left]) right = m - 1;
			else left = m + 1;
		}
	}
	return -1;
}

int main()
{
	int a[] = {378, 478, 550, 631, 103, 203, 220, 234, 279, 368};
	int n = 10;
	int key = 478;
	cout << "Testing input: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "Search for 478" << endl;
	cout << "Result: " << findElement(a,n,key) << endl;
	return 0;
}
