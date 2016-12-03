#include <bits/stdc++.h>

using namespace std;

bool SearchElement(vector<vector<int>>& A, int x)
{
	// search from top right
	int row = 0, col = A[0].size() - 1;
	
	while (row < A.size() && col >= 0)
	{
		if (A[row][col] == x) return true;
		if (A[row][col] < x) row++;
		else col--;
	}
	return false;
}


