#include <bits/stdc++.h>

using namespace std;

unsigned long Divide(unsigned x, unsigned y)
{
	int power = 32;
	unsigned long long y_power = (unsigned long long) y << power;
	unsigned long res = 0;
	
	while (x >= y)
	{
		while (y_power > x)
		{
			y_power >>= 1;
			power--;
		}
	
		x -= y_power;
		res += 1U << power;
	}
	return res;
}

int main()
{
	unsigned x = 81, y = 9;
	cout << "Testing 81 / 9 Result: " << Divide(x, y) << endl;
	return 0;
}
