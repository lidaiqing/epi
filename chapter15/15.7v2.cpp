#include <bits/stdc++.h>

using namespace std;

// O(n) version

struct ABSQURT
{
	ABSQURT(int a, int b) : a(a), b(b), val(a + b * sqrt(2)) {}
	bool operator<(const ABSQURT& that) const
	{
		return val < that.val;
	}

	int a, b;
	double val;
};

vector<ABSQURT> FindFirstKNumber(int k)
{
	vector<ABSQURT> result;
	result.emplace_back(0,0);
	int i = 0, j = 0;
	while (result.size() < k)
	{
		ABSQURT i_pluse(result[i].a+1,result[i].b);
		ABSQURT j_pluse(result[j].a, result[j].b + 1);
		result.emplace_back(min(i_pluse, j_pluse));
		if (result.back().val == i_pluse.val) i++;
		if (result.back().val == j_pluse.val) j++;
	}
	return result;
}

int main()
{
	cout << "Testing k = 5" << endl;
	vector<ABSQURT> result = FindFirstKNumber(5);
	cout << "Result: ";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i].a << "+" << result[i].b << "*sqrt(2) ";
	}
	cout << endl;
	return 0;
}
