#include <bits/stdc++.h>

using namespace std;

string nextNum(const string&);
string lookAndSay(int n)
{
	string seq = "1";
	for (int i = 0; i < n; i++)
	{
		seq = nextNum(seq);
	}
	return seq;
}

string nextNum(const string& seq)
{
	string res = "";
	for (int i = 0; i < seq.size(); i++)
	{
		int count = 1;
		while (i + 1 < seq.size() && seq[i] == seq[i+1])
		{
			count++;
			i++;
		}
		res += to_string(count) + seq[i];
	}

	return res;
}


int main()
{
	int n = 4;
	cout << "Testing the 4th lookandsay number" << endl;
	string ans = lookAndSay(n);
	cout << "Result: " << ans << endl;
	return 0;
}
