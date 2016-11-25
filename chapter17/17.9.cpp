#include <bits/stdc++.h>

using namespace std;

// cal maximum gain for a coins select game

int MaximumRevenue(const vector<int>& coins)
{
	int n = coins.size();
	int dp[n][n];

	// base case
	for (int i = 0; i < n; i++)
		dp[i][i] = coins[i];

	for (int i = 0; i < n - 1; i++)
		dp[i][i+1] = max(coins[i], coins[i+1]);

	// dp[i][j] means maximum revenue a player can get in this turn from i to j
	
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 2; j < n; j++)
		{

			// case1: choose coins[i]

			int choose_i = coins[i] + min(dp[i+2][j], dp[i+1][j-1]);

			// case2: choose coins[j]

			int choose_j = coins[j] + min(dp[i+1][j-1], dp[i][j-2]);

			dp[i][j] = max(choose_i, choose_j);
		}
	}

	return dp[0][n-1];
}

int main()
{
	cout << "Test coins: ";
	vector<int> coins{10,25,5,1,10,5};
	for (int i = 0; i < coins.size(); i++)
		cout << coins[i] << " ";
	cout << endl;
	cout << "Result: " << MaximumRevenue(coins) << endl;
	return 0;
}
