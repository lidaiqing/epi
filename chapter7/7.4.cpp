#include <bits/stdc++.h>

using namespace std;

int removeAndreplace(char A[], int size)
{
	// assume the size of A is enough
	// first delete 'b' and count # of 'a'

	int cnt_a = 0;
	int write_idx = 0;
	
	for (int i = 0; i < size; i++)
	{
		if (A[i] == 'a')
		{
			cnt_a++;
		}
		if (A[i] != 'b') {
			A[write_idx++] = A[i];
		}
	}

	// now calculate final size
	int final_size = write_idx + cnt_a;
	int cur_idx = write_idx - 1; // last char
	write_idx = final_size - 1;
	while (cur_idx >= 0)
	{
		if (A[cur_idx] == 'a')
		{
			A[write_idx--] = 'd';
			A[write_idx--] = 'd';
		} else {
			A[write_idx--] = A[cur_idx];
		}

		cur_idx--;
	}
	return final_size;
}

int main()
{
	char A[20] = {'a','c','d','b','b','c','a'};
	int n = 7;

	cout << "Testing input:" << endl;
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
	int new_size = removeAndreplace(A, n);
	cout << "Resulting:" << endl;
	for (int i = 0; i < new_size; i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}
