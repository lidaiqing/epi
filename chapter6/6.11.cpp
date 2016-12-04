#include <bits/stdc++.h>

using namespace std;

void RandomSampling(vector<int>& v, int k)
{
	default_random_engine seed((random_device())());
	for (int i = 0; i < k; i++)
	{
		swap(v[i], v[uniform_int_distribution<int>{i, static_cast<int>(v.size()) - 1}(seed)]);
	}
}

int main()
{
	vector<int> v{5,2,3,1,6,7,8};
	cout << "Testing input: ";
	for (auto &i : v)
		cout << i << " " ;
	cout << endl;
	RandomSampling(v, 5);
	cout << "Result: ";
	for (auto &i : v)
		cout << i << " " ;
	cout << endl;
	return 0;
}
