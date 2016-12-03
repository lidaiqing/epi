#include <bits/stdc++.h>

using namespace std;

// Rabin-Karp

// return the first postion a substr in a text

int RabinKarp(const string & t, const string & s)
{
	if (s.size() > t.size())
		return -1;
	
	const int kBase = 26;
	int t_hash = 0, s_hash = 0;
	int power_s = 1;
	for (int i = 0; i < s.size(); i++)
	{
		power_s = i ? power_s * kBase : 1;
		t_hash = t_hash * kBase + t[i];
		s_hash = s_hash * kBase + s[i];
	}

	for (int i = s.size() - 1; i < t.size(); i++)
	{
		// check if match or collision
		//cout << i << " " << t_hash << " " << s_hash << endl;
		if (t_hash == s_hash && !t.compare(i - s.size() + 1, s.size(), s))
			return i - s.size() + 1;
		if (i == t.size() - 1) break;
		t_hash -= t[i-s.size()+1] * power_s;
		t_hash = t_hash * kBase + t[i+1];
	}

	return -1;
}

int main()
{
	string s = "cca";
	string t = "gacgcca";

	cout << "Find the first index where " << t << " appears in " << s << endl;
	cout << "Result: " << RabinKarp(t, s) << endl;
	return 0;
}
