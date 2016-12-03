#include <bits/stdc++.h>

using namespace std;

// remove duplicate in one pass

int RemoveDup(vector<int>& v)
{
	if (v.empty())
		return 0;
	int write_idx = 1;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] != v[write_idx-1])
		{
			v[write_idx++] = v[i];
		}
	}
	return write_idx;
}

int main()
{
	vector<int> v{1,2,2,3,3,3,4,5,6,6,6};
	cout << "Testing input: ";
	for (auto &i : v)
		cout << i << " ";
	cout << endl;
	int newLen = RemoveDup(v);
	for (int i = 0; i < newLen; i++)
		cout << v[i] << " ";
	cout << endl;
	return 0;
}
