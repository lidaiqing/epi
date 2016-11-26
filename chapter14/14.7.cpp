#include <bits/stdc++.h>

using namespace std;

struct Person
{
	int age;
	string name;
};

void GroupByAge(vector<Person>& people)
{
	unordered_map<int,int> age_to_count;
	for (auto p& : people)
	{
		age_to_count[p.age]++;
	}

	unordered_map<int,int> age_to_offset;
	int offset = 0;
	for (auto p& : age_to_count)
	{
		age_to_offset[p.first] = offset;
		offset += p.second;
	}
	// swap in place
	while (age_to_offset.size())
	{
		auto from = age_to_offset.begin();
		auto to = age_to_offset.find(people[from->second].age);
		swap(people[from->second], people[to->second]);
		age_to_count[to->first]--;
		if (age_to_count[to->first] > 0)
		{
			to->second++;
		}
		else	age_to_offset.erase(to);
	}
}
