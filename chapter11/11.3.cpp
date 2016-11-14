#include <bits/stdc++.h>

using namespace std;

// sort an almost sorted array

vector<int> sort_array(int a[], int n, int k)
{
	priority_queue<int, vector<int>, greater<int> > pq;
	vector<int> ans;
	int idx = 0;
	for (; idx < k; idx++)
		pq.push(a[idx]);

	// keep k nums in the pq

	for (; idx < n; idx++)
	{
		pq.push(a[idx]);
		ans.push_back(pq.top());
		pq.pop();
	}

	// push the remaining nums

	while (!pq.empty())
	{
		ans.push_back(pq.top());
		pq.pop();
	}
	
	return ans;
}

int main()
{
	int a[] = {3, -1, 2, 6, 4, 5, 8};
	int n = 7;

	cout << "Testing input: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	vector<int> res = sort_array(a, n, 2);
	cout << "Resulting: ";
	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}
