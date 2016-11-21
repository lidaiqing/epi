#include <bits/stdc++.h>

using namespace std;

// find 3 sum

bool HasTwoSum(vector<int>& A, int target)
{
	int l = 0, r = A.size() - 1;
	while (l <= r)
	{
		if (A[l] + A[r] < target) l++;
		else if (A[l] + A[r] == target) return true;
		else r--;
	}

	return false;
}

bool HasThreeSum(vector<int>& A, int target)
{
	// allow reuse elements
	sort(A.begin(), A.end());
	for (int i = 0; i < A.size(); i++)
	{
		if (HasTwoSum(A, target-A[i])) return true;
	}

	return false;
}

int main()
{
	vector<int>A {11, 2, 5, 7, 3};
	cout << "Testing array: Three Sum of 21";
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " " ;
	cout << endl;
	cout << "Result: " << HasThreeSum(A, 21) << endl;
	return 0;
}
