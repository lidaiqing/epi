#include <bits/stdc++.h>

using namespace std;

// find the first k a+b*sqrt(2)
struct ABSQURT
{
	ABSQURT(int a, int b) : a(a), b(b), val(a+b*sqrt(2)) {}
	bool operator<(const ABSQURT& that) const
	{
		return val < that.val;
	}
	double val;
	int a, b;
};

vector<ABSQURT> FindFirstKNumber(int k)
{
	// use set to avoid duplicate

	set<ABSQURT> s;
	s.emplace(0,0);
	vector<ABSQURT> result;
	while (result.size() < k)
	{
		auto cur = s.begin();
		result.emplace_back(*cur);
		s.emplace(cur->a+1, cur->b);
		s.emplace(cur->a, cur->b+1);
		s.erase(cur);
	}
	return result;
}

int main()
{
	cout << "Testing k = 5" << endl;
	vector<ABSQURT> res = FindFirstKNumber(5);
	cout << "Result: ";
	for (int i = 0; i < res.size(); i++)
		cout << res[i].a << "+" << res[i].b << "*sqrt(2) ";
	cout << endl;
	return 0;
}
