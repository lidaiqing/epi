#include <bits/stdc++.h>

using namespace std;

bool IsPatternInGridRC(const vector<vector<int> >&grid, const vector<int> & pattern, vector<vector<vector<bool>>>& prev_attemps, int r, int c, int offset)
{
	if (offset == pattern.size()) return true;
	if (r < 0 || r >= grid.size() || c < 0 || c >= grid[r].size() || prev_attemps[r][c][offset]) return false;
	if (grid[r][c] == pattern[offset] &&
		(IsPatternInGridRC(grid, pattern, prev_attemps, r-1, c, offset + 1) || 
		 IsPatternInGridRC(grid, pattern, prev_attemps, r+1, c, offset + 1) ||
		 IsPatternInGridRC(grid, pattern, prev_attemps, r, c-1, offset + 1) ||
		 IsPatternInGridRC(grid, pattern, prev_attemps, r, c+1, offset + 1))) return true;
	prev_attemps[r][c][offset] = true;
	return false;
}
	

bool IsPatternInGrid(const vector<vector<int> > &grid, const vector<int> & pattern)
{
	// assume grid is not empty
	int n = grid.size(), m = grid[0].size();
	
	int k = pattern.size();
	vector<vector<vector<bool> > > prev_attemps(n, vector<vector<bool> >(m, vector<bool>(k, false)));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (IsPatternInGridRC(grid, pattern, prev_attemps, i, j, 0)) return true;
		}
	}
	return false;
}

int main()
{
	vector<vector<int> > grid { {1,2,3}, {3,4,5}, {5,6,7} };
	vector<int> pattern{ 1,3,4,6};
	cout << "Find 1, 3, 4, 6 " << endl;

	cout << "Result: " << IsPatternInGrid(grid, pattern) << endl;
	return 0;
}
	

	
