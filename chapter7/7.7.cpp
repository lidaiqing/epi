#include <bits/stdc++.h>

using namespace std;

string letter_map[10] = {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
void phone_memo_helper(int, const string&, string&, vector<string>&);

vector<string> phone_memo(const string& phone_num)
{
	vector<string> res;
	string partial(phone_num.size(), '0');
	phone_memo_helper(0, phone_num, partial, res);
	return res;
}

void phone_memo_helper(int cur, const string& phone_num, string& partial, vector<string>& res)
{
	if (cur == phone_num.size())
	{
		// arrive the last digit
		res.push_back(partial);
		return;
	}
	
	int digit = phone_num[cur] - '0';
	for (int i = 0; i < letter_map[digit].size(); i++)
	{
		char letter = letter_map[digit][i];
		partial[cur] = letter;
		phone_memo_helper(cur+1, phone_num, partial, res);
	}
}

int main()
{
	string input = "2276";
	cout << "Testing input: " << input << endl;
	vector<string> ans = phone_memo(input);
	cout << "Result:" << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
