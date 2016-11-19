#include <bits/stdc++.h>

using namespace std;

// generate power set


vector<vector<int> > GeneratePowerSet(const vector<int>& input)
{
	int n = input.size();
	// loop all possible cominations
	vector<vector<int> > res;
	for (int i = 0; i < (1 << n); i++)
	{
		int bitmask = i;
		vector<int> temp;
		while (bitmask)
		{
			// isolate last bit
			temp.push_back(input[log2((bitmask)&~(bitmask-1))]);
			// get rid of last bit
			bitmask &= (bitmask - 1);
		}
		res.push_back(temp);
	}

	return res;
}

int main()
{
	cout << "Generating power set of 1, 2, 3, 4" << endl;
	vector<int> input {1, 2, 3, 4};
	vector<vector<int> > res = GeneratePowerSet(input);
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
		
