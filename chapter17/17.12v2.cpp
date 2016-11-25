#include <bits/stdc++.h>

using namespace std;


// this version is O(nlogn) time

int LongestNonDecreasingLength(const vector<int>& V)
{
	vector<int> M; // M maintains a longest non decreasing sequence

	for (int i = 0; i < V.size(); i++)
	{
		auto it = upper_bound(M.begin(), M.end(), V[i]);
		if (it == M.end())
		{ 
			// V[i] is the largest number in the sequence
			M.emplace_back(V[i]);
		}
		else
		{
			// replace old value with smaller value
			*it = V[i];
		}
	}

	// now M contains longest sequence
	return M.size();
}

int main()
{
	vector<int> v{0,8,4,12,2,10,6,14,1,9};
	cout << "Testing input: " << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	cout << "Result: " << LongestNonDecreasingLength(v) << endl;
	return 0;
}
