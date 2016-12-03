#include <bits/stdc++.h>

using namespace std;

// implement stack API using heap

class Stack
{
	public:
		void Push(int x)
		{
			max_heap_.emplace(ValueWithRank{timestamp_++, x});
		}

		int Pop()
		{
			if (max_heap_.empty())
				throw length_error("Empty Stack");
			int rank = max_heap_.top();
			max_heap_.pop();
			return rank;
		}

		int Peek()
		{
			return max_heap_.top().rank;
		}

	private:
		int timestamp_ = 0;
		struct ValueWithRank
		{
			int val, rank;
			bool operator<(const ValueWithRank& that) const
			{
				return val < that.val;
			}
		};

		priority_queue<ValueWithRank, vector<ValueWithRank> > max_heap_;
}
