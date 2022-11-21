#ifndef ___Wrod_Ladder_127_h___
#define ___Wrod_Ladder_127_h___
//https://leetcode.com/problems/word-ladder/
// 127. Word Ladder
#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

		unordered_map<string, int> wordMap(wordList.begin(), wordList.end());

		if (wordMap.find(endWord) == wordMap.end())
			return 0;

		queue<string> q;
		q.push(beginWord);
		int step = 1;
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				string word = q.front();
				q.pop();
				if (word == endWord)
				{
					return step;
				}
				for (int j = 0; j < word.size(); j++)
				{
					char c = word[j];
					for (int k = 0; k < 26; k++)
					{
						word[j] = 'a' + k;
						if (wordMap.find(word) != wordMap.end())
						{
							q.push(word);
							wordMap.erase(word);
						}
					}
					word[j] = c;
				}
			}
			step++;
		}
		return 0;

	}
};

#endif // ___Wrod_Ladder_127_h___
