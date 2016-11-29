#include <bits/stdc++.h>

using namespace std;

// implementation of run length encoding

string Decode(const string& s)
{
	string result = "";
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i]))
		{
			count = 10 * count + (s[i] - '0');
		}
		else
		{
			result.append(count, s[i]);
			count = 0;
		}
	}
	return result;
}

string Encode(const string& s)
{
	string result = "";
	int count = 1;
	for (int i = 1; i <= s.size(); i++)
	{
		if (i == s.size() || s[i] != s[i-1])
		{
			result += to_string(count) + s[i-1];
			count = 1;
		}
		else
		{
			count++;
		}
	}
	return result;
}

int main()
{
	string input = "4a1b3c2a";
	cout << "Testing decode " << input << endl;
	string decode = Decode(input);
	cout << "Result: " << decode << endl;
	cout << "Testing encode " << decode << endl;
	string encode = Encode(decode);
	cout << "Result: " << encode << endl;
	return 0;
}
