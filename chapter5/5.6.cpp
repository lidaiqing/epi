#include <bits/stdc++.h>

using namespace std;

double Power(double x, int y)
{
	if (y < 0)
	{
		y = -y;
		x = 1.0 / x;
	}

	double res = 1.0;
	while (y)
	{
		if (y & 1)
		{
			res *= x;
		}
		x *= x;
		y >>= 1;
	}
	return res;
}

int main()
{
	cout << "Testing pow(6, 36) " << endl;
	cout << "Result: " << Power(6,36) << endl;
	return 0;
}

	
