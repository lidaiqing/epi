#include <bits/stdc++.h>

using namespace std;

// O(n) time O(1) space solution to find majority element

char FindMajorityElement(string input)
{
	int candidate_count = 1;
	char cur_candidate = input[0];

	for (int i = 1; i < input.size(); i++)
	{
		if (candidate_count == 0)
		{
			cur_candidate = input[i];
			candidate_count = 1;
		}
		else
		{
			if (input[i] == cur_candidate) candidate_count++;
			else candidate_count--;
		}
	}

	return cur_candidate;
}

int main()
{
	string s = "bacaabaaca";

	cout << "Testing string: " << s << endl;
	cout << "Result: " << FindMajorityElement(s) << endl;
	return 0;
}
