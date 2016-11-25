#include <bits/stdc++.h>

using namespace std;


bool isPalindrome(const string& s)
{
	for (int i = 0; i < s.size() / 2; i++)
		if (s[i] != s[s.size()-1-i]) return false;
	return true;
}

void PalindromePartitionHelper(const string& input, int offset, vector<string> tmp, vector<vector<string> >& result)
{
	if (offset == input.size())
	{
		result.emplace_back(tmp);
		return;
	}
	for (int i = offset + 1; i <= input.size(); i++)
	{
		string s = input.substr(offset, i - offset);
		if (isPalindrome(s))
		{
			tmp.emplace_back(s);
			PalindromePartitionHelper(input, offset+1, tmp, result);
			tmp.pop_back();
		}
	}
}

	
vector<vector<string> > PalindromePartition(const string& input)
{
	vector<vector<string> > result;
	vector<string> tmp;
	PalindromePartitionHelper(input, 0, tmp, result);
	return result;
}

int main()
{
	string input = "0204451881";
	cout << "Testing input: " << input << endl;
	vector<vector<string> > res = PalindromePartition(input);
	cout << "Result: " << endl;
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	return 0;
}	
