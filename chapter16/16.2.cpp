#include <bits/stdc++.h>

using namespace std;

// compute n queens placement

bool isValid(const vector<int> & col_placement)
{
	int row_id = col_placement.size() - 1;
	for (int i = 0; i < row_id; i++)
	{
		int diff = abs(col_placement[row_id] - col_placement[i]);
		if (col_placement[i] == col_placement[row_id] || diff == row_id - i) return false;
	}
	return true;
}

void ComputeQueensHelper(vector<vector<int>>&res, vector<int> col_placement, int cur, int boardsize)
{
	if (cur == boardsize)
	{
		res.push_back(col_placement);
		return;
	}

	for (int i = 0; i < boardsize; i++)
	{
		col_placement.push_back(i);
		if (isValid(col_placement))
			ComputeQueensHelper(res, col_placement, cur + 1, boardsize);
		col_placement.pop_back();
	}
}		


vector<vector<int>> ComputeQueens(int n)
{
	vector<vector<int> > res;
	vector<int> col_placement;
	ComputeQueensHelper(res, col_placement, 0, n);
	return res;
}

int main()
{
	cout << "Testing board size 4" << endl;
	vector<vector<int> > res = ComputeQueens(4);

	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
	
