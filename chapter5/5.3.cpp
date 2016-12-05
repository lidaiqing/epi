#include <bits/stdc++.h>

using namespace std;

long SwapBits(long x, int i, int j)
{
	if ((x & (1L << i)) != (x & (1L << j)))
	{
		long bitmask = (1L << i) | (1L << j);
		x ^= bitmask;
	}
	return x;
}

vector<long> BuildHashTable()
{
	vector<long> table(1<<16, 0);

	for (long i = 0; i < (1 << 16); i++)
	{
		long num = i;
		long revnum = num;
		for (int j = 0; j < 8; j++)
		{
			revnum = SwapBits(revnum, j, 15 - j);
		}
		table[num] = revnum;
		//cout << num << " " << revnum << endl;
	}
	return table;
}

long ReverseBits(long x)
{
	vector<long> HashTable = BuildHashTable();
	int kSize = 16;
	int kMask = 0xFFFF;
	return HashTable[x & kMask] << (3 * kSize) |
		HashTable[(x >> kSize) & kMask] << (2 * kSize) |
		HashTable[(x >> (2 * kSize)) & kMask] << (kSize) |
		HashTable[(x >> (3 * kSize)) & kMask];
}

int main()
{
	long x = 2;
	cout << "Revsersing " << x << endl;
	cout << "Result: " << ReverseBits(x) << endl;
	return 0;
}
