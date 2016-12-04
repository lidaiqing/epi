#include <bits/stdc++.h>

using namespace std;

void RotateMatrix(vector<vector<int>> &A)
{
	int matrix_size = A.size() - 1;
	
	for (int i = 0; i < (matrix_size / 2); i++)
	{
		for (int j = i; j < matrix_size - i; j++)
		{
			int a = A[matrix_size-j][i];
			int b = A[matrix_size-i][matrix_size-j];
			int c = A[j][matrix_size-i];
			int d = A[i][j];
			
			A[i][j] = a;
			A[matrix_size-j][i] = b;
			A[matrix_size-i][matrix_size-j] = c;
			A[j][matrix_size-i] = d;
		}
	}
}

int main()
{
	vector<vector<int> > A{ {1,2,3}, {4,5,6}, {7,8,9}};

	RotateMatrix(A);
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[i].size(); j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
