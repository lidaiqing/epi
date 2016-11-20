#include <bits/stdc++.h>

using namespace std;

// edit distance between two strings

int CalDistanceBetween(string s1, string s2)
{
	int n = s1.size(), m = s2.size();

	int dp[n+1][m+1];
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
		dp[i][0] = i;
	for (int i = 1; i <= m; i++)
		dp[0][i] = i;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
			else
			{
				int substitute = dp[i-1][j-1];
				int deletes1 = dp[i][j-1];
				int adds1 = dp[i-1][j];
				dp[i][j] = 1 + min(substitute, min(deletes1, adds1));
			}
		}
	}

	return dp[n][m];
}

int main()
{
	string s1 = "Saturday";
	string s2 = "Sundays";
	cout << "Coumputing distance between " << s1 << " " << s2 << endl;
	int dis = CalDistanceBetween(s1, s2);
	cout << "Result: " << dis << endl;
	return 0;
}
