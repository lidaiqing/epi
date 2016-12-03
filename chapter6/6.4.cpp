#include <bits/stdc++.h>

using namespace std;

bool CanReachEnd(const vector<int>& v)
{
	int furthest = 0, last = v.size() - 1;
	for (int i = 0; i < v.size() && furthest < last; i++)
	{
		furthest = max(furthest, i + v[i]);
	}
	return furthest >= last;
}

int main()
{
	vector<int> input{3,3,1,0,2,0,1};

	cout << "Testing input: ";
	for (auto& i : input)
		cout << i << " ";
	cout << endl;
	cout << "Result: " << CanReachEnd(input) << endl;
	return 0;
}
