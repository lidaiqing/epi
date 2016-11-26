#include <bits/stdc++.h>

using namespace std;

// compute grey code

bool IsdifferByOneBit(int a, int b)
{
	int diff = a ^ b;
	return diff && !(diff & (diff - 1));
}

bool ComputeGreyCodeHelper(int n, unordered_set<int>* history, vector<int>& result)
{
	if (result.size() == (1 << n))
	{
		return IsdifferByOneBit(result.back(), result.front());
	}

	for (int i = 0; i < n; i++)
	{
		int cur = result.back();
		int next = (cur ^ (1 << i));
		if (history->find(next) == history->end())
		{
			history->emplace(next);
			result.emplace_back(next);
			if (ComputeGreyCodeHelper(n, history, result)) return true;
			result.pop_back();
			history->erase(next);
		}
	}
	return false;
}

vector<int> ComputeGreyCode(int n)
{
	// generate n bits grey code

	vector<int> result{0};
	ComputeGreyCodeHelper(n, new unordered_set<int>{0}, result);
	return result;
}

int main()
{
	cout << "Generating grey code of size 3" << endl;
	vector<int> result = ComputeGreyCode(3) ;
	cout << "Result: ";
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " " ;
	cout << endl;
	return 0;
}

	
