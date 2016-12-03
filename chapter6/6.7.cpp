#include <bits/stdc++.h>

using namespace std;

// cal maximun profit with at most two operations

int FindMaxProfit(const vector<int>& v)
{
	int max_total = INT_MIN;
	int min_so_far = INT_MAX;
	vector<int> first_buy_sell(v.size(), 0);
	for (int i = 0; i < v.size(); i++)
	{
		min_so_far = min(min_so_far, v[i]);
		max_total = max(max_total, v[i] - min_so_far);
		first_buy_sell[i] = max_total;
	}
	
	int max_so_far = INT_MIN;
	for (int i = v.size()-1; i >= 0; i--)
	{
		max_so_far = max(max_so_far, v[i]);
		max_total = max(max_total, first_buy_sell[i-1] + max_so_far - v[i]);
	}
	return max_total;
}

int main()
{
	vector<int> v{12,11,13,9,12,8,14,13,15};
	cout << "Testing input: ";
	for (auto& i: v)
		cout << i << " ";
	cout << endl;
	cout << "Result: " << FindMaxProfit(v) << endl;
	return 0;
}
