#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
#include<stack>
#include<cmath>
using namespace std;

// https://leetcode.com/problems/word-pattern/description/
//290. Word Pattern
#ifndef ___Word_Pattern_290_h___
#define ___Word_Pattern_290_h___
class Solution {
public:
	vector<string> split_string(string& pattern, char delimiter = ' ')
	{
		// make code to split string, delimiter is blank ' '
		vector<string> result;
		stringstream ss(pattern);
		string temp;
		while (getline(ss, temp, delimiter))
			result.push_back(temp);
		return result;
	}
	bool wordPattern(string pattern, string s) {

		vector<string> splited = split_string(s);

		unordered_map<char, string> pattern_map;
		unordered_map<string, char> string_map;

		if (pattern.size() != splited.size())
			return false;

		for (int i = 0; i < pattern.size(); i++)
		{
			//case 1 : 처음 나오는 패턴
			if (pattern_map.find(pattern[i]) == pattern_map.end())
			{
				//case 1 - 1 : 처음 나오는 문자열
				if (string_map.find(splited[i]) == string_map.end())
				{
					pattern_map[pattern[i]] = splited[i];
					string_map[splited[i]] = pattern[i];
				}
				// case 1 - 2 : 이미 나온 문자열
				else
					return false;
			}
			//case 2 : 이미 나온 패턴
			else
			{
				// 2 - 1 : 불일치하는 문자열
				if (pattern_map[pattern[i]] != splited[i])
					return false;
				// 2 - 1 : 일치하는 문자열
				//else
				//	continue;
			}
		}

		return true;
	}
};
/*
int main() {
	unique_ptr<Solution> sol(new Solution());
	cout << sol->wordPattern("abba", "dog cat cat dog") << "\n\n"; // 1
	cout << sol->wordPattern("abba", "dog cat cat fish") << "\n\n"; // 0
	cout << sol->wordPattern("aaaa", "dog cat cat dog") << "\n\n"; // 0
	cout << sol->wordPattern("abba", "dog dog dog dog") << "\n\n"; // 0
	cout << sol->wordPattern("aaa", "aa aa aa aa") << "\n\n"; // 0
	return 0;
}
*/
#endif // ___Word_Pattern_290_h___