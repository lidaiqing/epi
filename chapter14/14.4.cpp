#include <bits/stdc++.h>

using namespace std;

struct Event {
	int start, end;
};

struct Endpoint {

	bool operator < (const Endpoint& e) const
	{
		return (time != e.time ? time < e.time : (isStart && !e.isStart));
	}

	int time;
	bool isStart;
};


int findMaxSimuEvents(const vector<Event>& A)
{
	vector<Endpoint> E;
	for (int i = 0; i < A.size(); i++)
	{
		E.push_back({A[i].start, true});
		E.push_back({A[i].end, false});
	}

	sort(E.begin(), E.end());

	int maxEventCount = 0, eventCount = 0;

	for (int i = 0; i < E.size(); i++)
	{
		if (E[i].isStart) {
			eventCount++;
			maxEventCount = max(maxEventCount, eventCount);
		} else eventCount--;
	}

	return maxEventCount;
}

int main()
{
	vector<Event> A{ {1,5}, {6, 10}, {11,13}, {14,15}, {2,7}, {4,5}, {8,9}, {12,15}, {9,17}};

	cout << "Testing" << endl;
	cout << "Result: "<< findMaxSimuEvents(A) << endl;
	return 0;
}
