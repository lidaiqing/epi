#include <bits/stdc++.h>

using namespace std;

struct GraphVertex
{
	int label;
	vector<GraphVertex*> edges;
};

GraphVertex* CloneGraph(GraphVertex* u)
{
	if (!u) return nullptr;

	// clone graph reachable from u assume no cycle

	unordered_map<GraphVertex*, GraphVertex*> vertex_map;
	queue<GraphVertex*> q;

	q.emplace(u);
	vertex_map.emplace(u, new GraphVertex ({u->label}));

	while (!q.empty())
	{
		GraphVertex* f(q.front());
		q.pop();
		for (GraphVertex* v : f->edges)
		{
			if (vertex_map.find(v) == vertex_map.end())
			{
				vertex_map.emplace(v, new GraphVertex({v->label}));
				q.emplace(v);
			}
			vertex_map[f]->edges.emplace_back(vertex_map[v]);
		}
	}
	return vertex_map[u];
}

int main()
{
	return 0;
}
