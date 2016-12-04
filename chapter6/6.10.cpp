#include <bits/stdc++.h>

using namespace std;

// find next permutation in O(n)

vector<int> NextPermutation(vector<int> v)
{
	vector<int> res = v;
	
	int k = res.size() - 2;
	while (k >= 0 && res[k] >= res[k+1])
	{
		k--;
	}

	if (k == -1)
		return {};
	// find the first number that is greater than v[k]

	for (int i = res.size() - 1; i > k; i--)
	{
		if (res[i] > res[k])
		{
			swap(res[i], res[k]);
			break;
		}
	}

	reverse(res.begin()+k+1, res.end());
	return res;
}

int main()
{
	vector<int> v{6,2,1,5,4,3,0};
	cout << "Testing input: ";
	for (auto &i:v)
		cout << i << " ";
	cout << endl;
	cout << "Result: ";
	vector<int> res = NextPermutation(v);
	for (auto &i:res)
		cout << i << " ";
	cout << endl;
}
