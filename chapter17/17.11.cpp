#include <bits/stdc++.h>

using namespace std;



int MinimumMessness(const vector<string>& words, int line_length)
{
	vector<int> M(words.size(), INT_MAX);

	int remain_blanks = line_length - words[0].size();
	int cur_messness = remain_blanks * remain_blanks;
	M[0] = cur_messness;

	for (int i = 1; i < words.size(); i++)
	{
		remain_blanks = line_length - words[i].size();
		cur_messness = remain_blanks * remain_blanks;
		M[i] = M[i-1] + cur_messness;
		// try all sub words
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			remain_blanks -= (words[j].size() + 1);
			if (remain_blanks < 0) break; 
			cur_messness = remain_blanks * remain_blanks;
			int total_messness = cur_messness + (j - 1 < 0 ? 0 : M[j-1]);
			M[i] = min(M[i], total_messness);
		}
	}

	return M.back();
}

int main()
{
	string text = "I have inserted a large number of new examples from the papers for the Mathematical Tripos during the last twenty years, which should be useful to Cambridge students.";
	stringstream stext(text);
	vector<string> words;
	string buff;
	while (stext >> buff)
	{
		//cout << buff << endl;
		words.emplace_back(buff);
	}

	cout << "Testing input: " << endl;
	cout << text << endl;
	cout << "Result: " << MinimumMessness(words, 36) << endl;
	return 0;
}
