#include <bits/stdc++.h>

using namespace std;

string conver_base(const string& s, int b1, int b2) // convert s from base b1 to b2
{
	bool is_negtive = (s[0] == '-');
	// first convert s from b1 to integer base 10

	int x = 0;
	for (int i = (is_negtive ? 1 : 0); i < s.size(); i++)
	{
		x *= b1;
		int digit = (isdigit(s[i]) ? s[i] - '0' : s[i] - 'A' + 10);
		x += digit;
	}
	// convert x to base 2

	string res = "";
	while (x)
	{
		int digit = x % b2;
		res += (char)(digit >= 10 ? 'A' + digit - 10 : '0' + digit);
		x /= b2;
	}
	// add sign
	res += (is_negtive ? "-" : "");
	// reverse string
	reverse(res.begin(), res.end());

	return res;
}

int main()
{
	string input = "-615";
	int b1 = 7, b2 = 13;
	cout << "Testing input " << input << endl;
	string output = conver_base(input, b1, b2);
	cout << "Result: " << output << endl;
	return 0;
}
