#include <bits/stdc++.h>

using namespace std;

struct Interval
{
	int left;
	int right;
};

vector<int> FindMinCover(vector<Interval> V)
{
	sort(V.begin(), V.end(), [](const Interval& a, const Interval& b) -> bool {
	return a.right < b.right;
	});
	
	vector<int> cover;
	int last_cover = V.front().right;
	cover.emplace_back(last_cover);
	for (int i = 1; i < V.size(); i++)
	{
		if (V[i].left > last_cover)
		{
			cover.emplace_back(V[i].right);
			last_cover = V[i].right;
		}
	}
	return cover;
}

int main()
{
	vector<Interval> V{ {1,2}, {2,3}, {3,4}, {2,3}, {3,4}, {4,5} };

	cout << "Testing intervals: " << endl;
	for (auto i : V)
	{
		cout << "[" << i.left << "," << i.right << "]" << endl;
	}

	cout << "Result: ";
	vector<int> res = FindMinCover(V);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}
