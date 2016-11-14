#include <bits/stdc++.h>

using namespace std;

// priority_queue custom comparision example


int returnMax(int a[], int n)
{
	priority_queue<int, vector<int>, function<bool(int, int)> >
			pq([](const int& a, const int& b) -> bool {
				return a < b;
			});

	for (int i = 0; i < n; i++)
	{
		pq.push(a[i]);
	}

	return pq.top();
}


int main()
{
	int a[] = {1,2,3,4,5,6,7};
	int n = 7;

	cout << "Testing list: ";
	for (int i = 0; i < n; i++)
		cout << a[i];
	cout << endl;

	cout << "Result: " << returnMax(a, n) << endl;
	return 0;
}



