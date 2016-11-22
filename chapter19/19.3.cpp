#include <bits/stdc++.h>

using namespace std;

void MarkBoundaryHelper(vector<vector<char>>& board, vector<vector<bool>>& visit, int r, int c)
{
	struct Node
	{
		int r;
		int c;
	};

	queue<Node> q;
	q.emplace(Node{r,c});
	while (!q.empty())
	{
		Node u = q.front();
		q.pop();
		int dr[] = {-1,1,0,0};
		int dc[] = {0,0,-1,1};
		for (int i = 0; i < 4; i++)
		{
			int rr = u.r + dr[i];
			int cc = u.c + dc[i];
			if (rr >= 0 && rr < board.size() && cc >= 0 && cc < board[0].size() && !visit[rr][cc] && board[rr][cc] == 'W')
			{
				visit[rr][cc] = true;
				q.emplace(Node{r,c});
			}
		}
	}
}


void MarkBoundary(vector<vector<char>>& board)
{
	vector<vector<bool> > visit(board.size(), vector<bool>(board[0].size(), false));

	for (int i = 0; i < board.size(); i++)
	{
		if (board[i][0] == 'W' && !visit[i][0])
		{
			visit[i][0] = true;
			MarkBoundaryHelper(board, visit, i, 0);
		}
		
		if (board[i][board[0].size()-1] == 'W' && !visit[i][0])
		{
			visit[i][board[0].size()-1] = true;
			MarkBoundaryHelper(board, visit, i, board[0].size()-1);
		}
	}

	for (int j = 0; j < board[0].size(); j++)
	{
		if (board[0][j] == 'W' && !visit[0][j])
		{
			visit[0][j] = true;
			MarkBoundaryHelper(board, visit, 0, j);
		}

		if (board[board.size()-1][j] == 'W' && !visit[board.size()-1][j])
		{
			visit[board.size()-1][j] = true;
			MarkBoundaryHelper(board, visit, board.size()-1, j);
		}
	}

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] == 'W' && !visit[i][j]) board[i][j] = 'B';
		}
	}

}

int main()
{
	vector<vector<char>> board { {'B','B','B','B'}, {'W', 'B', 'W', 'B'}, {'B','W','W','B'}, {'B','B','B','B'}};

	MarkBoundary(board);
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			cout << board[i][j] << " " ;
		}
		cout << endl;
	}
	return 0;
}
