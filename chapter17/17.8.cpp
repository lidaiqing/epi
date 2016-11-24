#include <bits/stdc++.h>

using namespace std;

int MinimumPathWeight(const vector<vector<int>>& triangle)
{
	if (triangle.empty()) return 0;

	vector<int> prev_row(triangle.front());

	for (int i = 1; i < triangle.size(); i++)
	{
		vector<int> cur_row(triangle[i]);
		cur_row.front() += prev_row.front();
		for (int j = 1; j < triangle[i].size() - 1; j++)
			cur_row[j] += min(prev_row[j-1], prev_row[j]);
		cur_row.back() += prev_row.back();

		// constant swap vector

		prev_row.swap(cur_row);
	}

	// now we are in the last row

	return *min_element(prev_row.cbegin(), prev_row.cend());
}


int main()
{
	vector<vector<int>> triangle{ {2},{4,4},{8,5,6},{4,2,6,2},{1,5,2,3,4}};

	cout << "Testing triangle: " << endl;
	for (int i = 0; i < triangle.size(); i++)
	{
		for (int j = 0; j < triangle[i].size(); j++)
			cout << triangle[i][j] << " ";
		cout << endl;
	}

	cout << "Minimun path weight is " << MinimumPathWeight(triangle) << endl;
	return 0;
}
