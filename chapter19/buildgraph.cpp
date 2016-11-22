#include <bits/stdc++.h>

using namespace std;

struct MatchResult
{
	string win_team;
	string lost_team;
};

unordered_map<string, unordered_set<string> >
BuildGraph(const vector<MatchResult>& V)
{
	unordered_map<string, unordered_set<string> > graph;

	for (auto result : V)
	{
		graph[result.win_team].emplace(result.lost_team);
	}

	return graph;
}

int main()
{
	vector<MatchResult> V{{"a", "b"}, {"c", "d"} };
	BuildGraph(V);
	return 0;
}
