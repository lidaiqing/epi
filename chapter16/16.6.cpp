#include <bits/stdc++.h>

using namespace std;

// generate all valid parathesses


void GenerateKPairParasHelper(int left, int right, string tmp, vector<string>& result)
{
	if (left == 0 && right == 0)
	{
		result.emplace_back(tmp);
		return;
	}

	if (left > 0)
	{
		GenerateKPairParasHelper(left - 1, right, tmp + "(", result);
	}
	
	if (left < right)
	{
		GenerateKPairParasHelper(left, right - 1, tmp + ")", result);
	}
}

vector<string> GenerateKPairParas(int k)
{
	vector<string> result;
	string s = "";
	GenerateKPairParasHelper(k, k, s, result);
	return result;
}

int main()
{
	cout << "Testing k = 3" << endl;

	vector<string> res;

	res = GenerateKPairParas(3);
	
	cout << "Result: " << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;

	return 0;
}

