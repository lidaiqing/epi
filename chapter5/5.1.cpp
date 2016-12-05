#include <bits/stdc++.h>

using namespace std;

// compute parity of a word

short Parity(unsigned long x)
{
	short res = 0;
	while (x)
	{
		res ^= 1;
		x &= (x - 1); // get rid of last one
	}
	return res;
}

void PreComputeTable(vector<unsigned long>& table)
{
	// store parity from 0 - 1 << 16

	for (int i = 0; i < (1 << 16); i++)
		table[i] = Parity(i);
}

short CachedParity(unsigned long x, const vector<unsigned long>& HashTable)
{
	// use cached result to do the computation

	int kSize = 16;
	int kMask = 0xFFFF;

	return HashTable[(x>>(3 * kSize))] ^ HashTable[(x>>(2 * kSize))&kMask] ^ HashTable[x>>(kSize)&kMask] ^ HashTable[x&kMask];
}

int main()
{
	vector<unsigned long> table(1<<16, 0);
	PreComputeTable(table);
	unsigned long x = 5678;
	cout << "Parity of " << x << " is " << CachedParity(x, table) << endl;
	return 0;
}
