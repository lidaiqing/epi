#include <bits/stdc++.h>

using namespace std;

unsigned long Add(unsigned long x, unsigned long y)
{
	unsigned long sum = 0;
	unsigned long carryin = 0;
	unsigned long k = 1;
	unsigned long temp_x = x, temp_y = y;
	while (temp_x || temp_y)
	{
		unsigned long xk = x & k;
		unsigned long yk = y & k;
		unsigned long carryout = (xk & yk) | (xk & carryin) | (yk & carryin);
		sum |= (carryin ^ xk ^ yk);
		carryin = carryout << 1;
		temp_x >>= 1, temp_y >>= 1, k <<= 1;
	}
	return sum | carryin;
}

unsigned long Multiply(unsigned long x, unsigned long y)
{
	unsigned long sum = 0;
	while (x)
	{
		if (x & 1)
		{
			sum = Add(sum, y);
		}
		x >>= 1;
		y <<= 1;
	}
	return sum;
}

int main()
{
	unsigned long x = 123, y = 456;
	cout << "Testing " << x << " * " << y << endl;
	cout << "Result: " << Multiply(x,y) << endl;
	return 0;
} 
