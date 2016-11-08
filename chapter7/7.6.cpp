#include <bits/stdc++.h>

using namespace std;

void reverseWords(string & s)
{
	reverse(s.begin(), s.end());
	// now reverse each words in s

	int start = 0;
	int end;
	while ((end = s.find(' ', start)) && end != string::npos)
	{
		reverse(s.begin() + start, s.begin() + end);
		start = end + 1;
	}
	reverse(s.begin() + start, s.end());
}


int main()
{
	string input = "ram is costly";

	cout << "Testing input " << input << endl;
	reverseWords(input);
	cout << "Resulting: " << input << endl;
	return 0;
}
