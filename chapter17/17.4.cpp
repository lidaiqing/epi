#include <bits/stdc++.h>

using namespace std;

// compute combination (n, k) with O(k) space


int Combination(int n, int k)
{
	// make sure k is < n - k
	if (k > n - k) k = n - k;
	int dp[2][k+1];
	
	for (int i = 0; i <= k; i++)
	{
		dp[0][i] = 1;
		dp[1][i] = 1;
	}

	int cur = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= min(i,k); j++)
		{
			dp[cur][j] = dp[1-cur][j-1] + dp[1-cur][j];
		}
		cur = 1 - cur;
	}

	return dp[cur][k];
}

int main()
{
	cout << "Test 5 choose 2" << endl;
	cout << "Result: " << Combination(5,2) << endl;
	cout << "Test 10 choose 7" << endl;
	cout << "Result: " << Combination(10,7) << endl;
	return 0;
}
