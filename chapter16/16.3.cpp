#include <bits/stdc++.h>

using namespace std;

// generate all permutation of a vector


void GenerateAllPermutationHelper(int offset, vector<int>& tmp, vector<vector<int>>& result)
{
	if (offset == tmp.size()-1)
	{
		result.emplace_back(tmp);
	}

	for (int i = offset; i < tmp.size(); i++)
	{
		swap(tmp[offset], tmp[i]);
		GenerateAllPermutationHelper(offset + 1, tmp, result);
		swap(tmp[offset], tmp[i]);
	}
}

vector<vector<int> > GenerateAllPermutation(vector<int> V)
{
	vector<vector<int>> result;
	GenerateAllPermutationHelper(0, V, result);
	return result;
}


int main()
{
	vector<int> input{1,2,3,4,5};
	cout << "Testing input: ";
	for (int i = 0; i < input.size(); i++)
		cout << input[i] << " ";
	cout << endl;

	vector<vector<int> > result = GenerateAllPermutation(input);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " " ;
		}
		cout << endl;
	}

	return 0;
}
