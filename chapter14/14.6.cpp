#include <bits/stdc++.h>

using namespace std;

struct Interval {
	private:
		struct Endpoint {
			int val;
			int isClosed;
		};
	public:
		bool operator<(const Interval& i) const
		{
			if (left.val != i.left.val)
			{
				return left.val < i.left.val;
			}

			return left.isClosed && !i.left.isClosed;
		}

	Endpoint left, right;
};


vector<Interval> UnionIntervals(vector<Interval> intervals)
{
	if (intervals.empty())
	{
		return {};
	}

	sort(intervals.begin(), intervals.end());

	Interval cur(intervals.front());

	vector<Interval> result;

	for (int i = 1; i < intervals.size(); i++)
	{
		if (intervals[i].left.val < cur.right.val ||
			(intervals[i].left.val == cur.right.val &&
				(intervals[i].left.isClosed || cur.right.isClosed)))
		{
			if ((intervals[i].right.val > cur.right.val) ||
				(intervals[i].right.val == cur.right.val && 
					intervals[i].right.isClosed))
			{
				cur.right = intervals[i].right;
			}
		}
		else
		{
			result.push_back(cur);
			cur = intervals[i];
		}
	}
	result.push_back(cur);
	return result;
}

int main()
{
	vector<Interval> intervals {{{0,false},{3,false}}, {{3,true},{4,false}},{{2,true},{4,true}}};

	cout << "Testing" << endl;
	vector<Interval> res = UnionIntervals(intervals);
	cout << "Results: "<< endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i].left.val << " " << (res[i].left.isClosed ? "closed " : "open ") << res[i].right.val << " " << (res[i].right.isClosed ? "closed " : "open ") << endl;
	}
	return 0;
}

	
