#include <bits/stdc++.h>

using namespace std;

// find minmax with fewer comparision

struct MinMax
{
	MinMax(int a, int b)
	{
		if (a > b) swap(a,b);
		min = a;
		max = b;
	}
	int min, max;
};

MinMax FindMinMax(const vector<int>& V)
{
	if (V.size() <= 1)
	{
		return MinMax{V.front(), V.front()};
	}
	MinMax gloable_minmax = MinMax{V[0], V[1]};
	for (int i = 2; i + 1 < V.size(); i += 2)
	{
		MinMax local_minmax = MinMax{V[i], V[i+1]};
		gloable_minmax.min = min(gloable_minmax.min, local_minmax.min);
		gloable_minmax.max = max(gloable_minmax.max, local_minmax.max);
	}
	if (V.size() % 2)
	{
		gloable_minmax.min = min(gloable_minmax.min, V.back());
		gloable_minmax.max = max(gloable_minmax.max, V.back());
	}
	return gloable_minmax;
}

int main()
{
	vector<int> V{1,3,2,5,-2,1,12,-2};
	cout << "Testing input: ";
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << " ";
	cout << endl;
	MinMax res = FindMinMax(V);
	cout << "Result: min " << res.min << " max " << res.max << endl;
	return 0;
}
