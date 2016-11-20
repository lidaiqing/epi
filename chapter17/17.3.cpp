#include <bits/stdc++.h>
using namespace std;

int ComputeNumberOfWaysRC(int r, int c, vector<vector<int> >& ways)
{
	if (r == 0 && c == 0) return 1;
	if (ways[r][c] == 0)
	{
		// count ways from top
		int top = r == 0 ? 0 : ComputeNumberOfWaysRC(r-1, c, ways);
		int left = c == 0 ? 0 : ComputeNumberOfWaysRC(r, c - 1, ways);
		ways[r][c] = top + left;
	}
	return ways[r][c];
}

int ComputeNumberOfWays(int n, int m)
{
	vector<vector<int> > ways(n, vector<int>(m, 0));
	return ComputeNumberOfWaysRC(n-1, m-1, ways);
}

int main()
{
	cout << "Computing number of ways from 0, 0 to 4, 4" << endl;
	int res = ComputeNumberOfWays(4, 4);

	cout << "Result: " << res << endl;
	return 0;
}
	
