#include <bits/stdc++.h>

using namespace std;

// find longest non-decresing sequence

int FindLongestNonDecreasing(const vector<int>& V)
{
	int n = V.size();
	int dp[n] = {1}; // length ends at i

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (V[j] <= V[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	return *max_element(dp, dp+n);
}


int main()
{
	vector<int> v{0,8,4,12,2,10,6,14,1,9};

	cout << "Testing input: ";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	cout << "Result: " << FindLongestNonDecreasing(v) << endl;
	return 0;
}
