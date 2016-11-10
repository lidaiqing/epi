#include <bits/stdc++.h>

using namespace std;

int evalRPN(const string& s)
{
	queue<int> q;
	stringstream ss(s);
	string token;
	char delimeter = ',';

	while (getline(ss, token, delimeter))
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			int x = q.front();
			q.pop();
			int y = q.front();
			q.pop();
			
			int result;
			if (token == "+") result = x + y;
			else if (token == "-") result = x - y;
			else if (token == "*") result = x * y;
			else result = x / y;
			q.push(result);
		} else {
			q.push(stoi(token));
		}
	}

	return q.front();
}


int main()
{
	string input = "3,4,+,2,*,1,+";

	cout << "Testing input: " << input << endl;
	int res = evalRPN(input);
	cout << "Result: " << res << endl;
	return 0;
}
