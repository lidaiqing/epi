#include <bits/stdc++.h>

using namespace std;

int square_root(int k)
{
	// O(logn) square root

	long long left = 0, right = k;
	while (left <= right)
	{
		long long m = left + (right - left) / 2;
		long long msquare = m * m;
		if (msquare <= k) left = m + 1;
		else right = m - 1;
	}

	return left - 1;
}

int main()
{
	int k = 20001123;
	cout << "Testing input: " << k << endl;
	cout << "Result: " << square_root(k) << endl;
	return 0;
}
