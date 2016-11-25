#include <bits/stdc++.h>

using namespace std;

struct GraphVertex
{
	bool visited = false;
	int max_distance = 1;
	vector<GraphVertex*> edges;
};

void DFS(GraphVertex* cur, stack<GraphVertex*>* vertex_order)
{
	cur->visited = true;
	for (GraphVertex* v : cur->edges)
	{
		if (!v->visited)
			DFS(v, vertex_order);
	}
	vertex_order->emplace(cur);
}
	

stack<GraphVertex*> BuildVertexOrder(vector<GraphVertex*>* G)
{
	stack<GraphVertex*> vertex_order;
	for (GraphVertex* u : *G)
	{
		if (!u->visited) DFS(u, &vertex_order);
	}
	return vertex_order;
}

int FindLongestPath(stack<GraphVertex*>& vertex_order)
{
	int max_dis = 0;
	while (!vertex_order.empty())
	{
		GraphVertex* t = vertex_order.top();
		vertex_order.pop();
		max_dis = max(max_dis, t->max_distance);
		for (GraphVertex* v : t->edges)
			v->max_distance = max(v->max_distance, t->max_distance+1);
	}
	return max_dis;
}

int FindMaxTeams(vector<GraphVertex*>* G)
{
	stack<GraphVertex*> vertex_order(BuildVertexOrder(G));
	return FindLongestPath(vertex_order);
}

int main()
{
	// assume the dependency between teams are given
	// or we can sort all teams and build graph

	return 0;
}
	
