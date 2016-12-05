#include <bits/stdc++.h>

using namespace std;

// swap bits

long SwapBits(long x, int i, int j)
{
	// first check if i and j bit in x are diff

	if ((x & (1L << i)) != (x & (1L << j)))
	{
		long bitmask = (1L << i) | (1L << j);

		// filp i , j bits in x

		x ^= bitmask;
	}
	return x;
}

int main()
{
	int x = 6;
	int i = 0, j = 1;
	cout << "Testing " << x << " after swap " << SwapBits(x, i, j) << endl;
	return 0;
}
