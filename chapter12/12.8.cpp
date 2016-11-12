#include <bits/stdc++.h>

using namespace std;

int partition(int a[], int left, int right, int pivot)
{
	int pivot_val = a[pivot];
	swap(a[pivot], a[right]);
	int new_idx = left;
	for (int i = left; i < right; i++)
	{
		if (a[i] < pivot_val)
		{
			swap(a[i], a[new_idx++]);
		}
	}
	//swap pivot to the right place

	swap(a[right], a[new_idx]);
	return new_idx;
}

int FindKthLargest(int a[], int n, int k)
{
	// set up rand function
	srand(time(NULL));
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int pivot = rand() % (right - left + 1) + left;
		int new_pivot = partition(a,left,right,pivot);
		if (new_pivot == k - 1)
		{
			return a[new_pivot];
		}
		else if (new_pivot < k - 1) left = new_pivot + 1;
		else right = new_pivot - 1;
	}
	return -1;
}

int main()
{
	int a[] = {3,1,5,2,-1,-5};
	int n = 6;
	int k = 3;
	cout << "Testing input: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	int res = FindKthLargest(a, n, k);
	cout << "Result: " << res << endl;
	return 0;
}















