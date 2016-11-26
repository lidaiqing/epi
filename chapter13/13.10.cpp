#include <bits/stdc++.h>

using namespace std;

int FindLongestInterval(const vector<int>& V)
{
	unordered_set<int> unprocessed(V.begin(), V.end());

	int max_size = 1;
	while (!unprocessed.empty())
	{
		int a = *unprocessed.begin();
		unprocessed.erase(a);

		int lower_bound = a - 1;
		while (unprocessed.find(lower_bound) != unprocessed.end())
		{
			unprocessed.erase(lower_bound);
			lower_bound--;
		}

		int upper_bound = a + 1;
		while (unprocessed.find(upper_bound) != unprocessed.end())
		{
			unprocessed.erase(upper_bound);
			upper_bound++;
		}
		max_size = max(max_size, upper_bound - lower_bound - 1);
	}
	return max_size;
}

int main()
{
	vector<int> V={3,-2,7,9,8,1,2,0,-1,5,8};

	cout << "Testing input: ";
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << " ";
	cout << endl;
	cout << "Result: " << FindLongestInterval(V) << endl;
	return 0;
}
			
