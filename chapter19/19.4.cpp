#include <bits/stdc++.h>

using namespace std;

// find cycle in an directed graph

struct GraphVertex
{
	enum Color {white, grey, black} color = white;
	vector<GraphVertex*> edges;
};

bool HasCycle(GraphVertex* cur, GraphVertex* prev)
{
	if (cur->color == GraphVertex::grey)
	{
		// found a back edge
		return true;
	}

	cur->color = GraphVertex::grey;
	// check all its neighboors
	for (GraphVertex*& next : cur->edges)
	{
		if (next->color != GraphVertex::black && next != prev)
		{
			if (HasCycle(next, cur))
				return true;
		}
	}
	cur->color = GraphVertex::black;
	return false;
}

bool IsDeadLock (vector<GraphVertex>* graph)
{
	for (GraphVertex& vertex : *graph)
	{
		if (vertex.color == GraphVertex::white && HasCycle(&vertex, NULL))
		return true;
	}
	return false;
}


int main()
{
	return 0;
}
