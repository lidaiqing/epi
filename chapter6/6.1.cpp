#include <bits/stdc++.h>

using namespace std;

void Reorder(vector<int>& v, int index)
{
	int small_ptr = 0;
	int large_ptr = v.size() - 1;
	int pivot = v[index];

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < pivot)
			swap(v[small_ptr++], v[i]);
	}

	for (int i = v.size() - 1; i >= 0 && v[i] >= pivot; i--)
	{
		if (v[i] > pivot)
			swap(v[large_ptr--], v[i]);
	}

}

int main()
{
	vector<int> input{6,5,4,4,4,3,2,1,1,1};
	cout << "Testing input: " << endl;
	for (auto &i : input)
		cout << i << " " ;
	cout << endl;
	Reorder(input, 2);
	for (auto &i : input)
		cout << i << " ";
	cout << endl;
	return 0;
}
	

