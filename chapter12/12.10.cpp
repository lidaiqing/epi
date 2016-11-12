#include <bits/stdc++.h>
using namespace std;
// finding the duplicated and missing bits

pair<int, int> findDupAndMiss(int a[], int n)
{
	int miss_XOR_dup = 0;
	for (int i = 0; i < n; i++)
		miss_XOR_dup ^= a[i] ^ i;
	
	int diff_bit = miss_XOR_dup & (~(miss_XOR_dup-1));

	int miss_OR_dup = 0;
	for (int i = 0; i < n; i++)
	{
		if (i & diff_bit) miss_OR_dup ^= i;
		if (a[i] & diff_bit) miss_OR_dup ^= a[i];
	}

	// check if it is in a
	for (int i = 0; i < n; i++)
	{
		if (miss_OR_dup == a[i])
		{
			return make_pair(a[i], miss_XOR_dup ^ miss_OR_dup);
		}
	}

	return make_pair(miss_OR_dup, miss_XOR_dup ^ miss_OR_dup);
}

int main()
{
	int a[] = {5,3,0,3,1,2};
	int n = 6;

	cout << "Testing input: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	pair<int,int> res = findDupAndMiss(a,n);
	cout << "Duplicated " << res.first << " Missed " << res.second << endl;
	return 0;
}
