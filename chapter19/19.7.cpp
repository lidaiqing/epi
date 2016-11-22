#include <bits/stdc++.h>

using namespace std;

// find minimun distance a string can be transformed to another using string in dictionary

int TransformString(unordered_set<string> dictionary, const string& s, const string& e)
{
	struct WordAndDistance
	{
		string word;
		int distance;
	};

	queue<WordAndDistance> q;
	dictionary.erase(s);
	q.emplace(WordAndDistance{s, 0});

	while (!q.empty())
	{
		WordAndDistance f(q.front());
		q.pop();
		cout << f.word << endl;
		if (f.word == e) return f.distance;


		// try all possible

		for (int i = 0; i < f.word.size(); i++)
		{
			string tmp = f.word;
			for (int j = 0; j < 26; j++)
			{
				tmp[i] = 'a' + j;
				if (dictionary.find(tmp) != dictionary.end())
				{
					dictionary.erase(tmp);
					q.emplace(WordAndDistance{tmp, f.distance + 1});
				}
			}

		}
	}
	return -1; // not found
}

int main()
{
	unordered_set<string> d ({"bat", "cot", "dog", "dag", "dot", "cat"});
	cout << "Find distance between cat and dog " << endl;
	
	string s = "cat";
	string e = "dog";
	cout << "Result: " << TransformString(d, s, e) << endl;
	
	return 0;
}
