#include <bits/stdc++.h>

using namespace std;

// mutiply two large number

vector<int> Multiply(vector<int>& num1, vector<int>& num2)
{
	// first determine the sign
	int sign = ((num1.front() < 0) ^ (num2.front() < 0)) ? -1 : 1;
	num1.front() = abs(num1.front());
	num2.front() = abs(num2.front());

	vector<int> result(num1.size() + num2.size(), 0);
	
	for (int i = num1.size() - 1; i >= 0; i--)
	{
		for (int j = num2.size() - 1; j >= 0; j--)
		{
			result[i+j+1] += num1[i] * num2[j];
			result[i+j] += result[i+j+1] / 10;
			result[i+j+1] %= 10;
		}
	}

	// get rid of leeading space

	int i = 0;
	while (i < result.size() && result[i] == 0) i++;
	if (i == result.size())
	{
		return result = vector<int>{0};
	}
	else
	{
		result = vector<int>(result.begin()+i, result.end());
		result.front() *= sign;
		return result;
	}
}

int main()
{
	vector<int> num1 = {-1,2,3};
	vector<int> num2 = {9,8,7};
	cout << "Testing -123 * 987 " << endl;
	vector<int> res = Multiply(num1,num2);
	cout << "Result: " << endl;
	for (auto & i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}
