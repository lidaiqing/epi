#include <bits/stdc++.h>

using namespace std;

struct Subarray {
	int start, end;
};

Subarray findSubArray(string text[], int n, string keywords[], int k)
{
	// use a list to track occurences of strings

	list<int> loc;
	unordered_map<string, list<int>::iterator> dict;

	for (int i = 0; i < k; i++)
		dict[keywords[i]] = loc.end();
	Subarray result = {-1, -1};
	
	for (int i = 0; i < n; i++)
	{
		auto it = dict.find(text[i]);
		if (it != dict.end())
		{
			if (it->second != loc.end()) loc.erase(it->second);
			loc.emplace_back(i);
			it->second = --loc.end();
		}
		
		if (loc.size() == k)
		{
			if ((result.start == -1 && result.end == -1) || (i - loc.front() < result.end - result.start))				{
				result.start = loc.front();
				result.end   = i;
			}
		}
	}

	return result;
}

int main()
{
	string text[] = {"apple", "banana", "apple", "apple", "dog", "cat", "apple", "dog", "banana", "apple", "cat", "god"};
	int n = 12;
	string keywords[] = {"banana", "cat"};
	int k = 2;

	cout << "Testing input: " << endl;
	for (int i = 0; i < n; i++)
		cout << text[i] << " ";
	cout << "Searching: " << endl;
	for (int i = 0; i < k; i++)
		cout << keywords[i] << " ";
	cout << endl;
	Subarray res = findSubArray(text, n, keywords, k);
	cout << "Result: " << res.start << " " << res.end << endl;
	return 0;
}
