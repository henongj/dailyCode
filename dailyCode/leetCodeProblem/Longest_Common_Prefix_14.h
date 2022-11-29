
#ifndef ___Longest_Common_Prefix_14_h___
#define ___Longest_Common_Prefix_14_h___
//https://leetcode.com/problems/longest-common-prefix/
//14. Longest Common Prefix
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";

		if (strs.size() == 1)
			return strs[0];

		string prefix = strs[0];
		for (int i = 1; i < strs.size(); i++)
		{
			int j = 0;
			for (; j < prefix.size() && j < strs[i].size(); j++)
			{
				if (prefix[j] != strs[i][j])
					break;
			}
			prefix = prefix.substr(0, j);
		}
		return prefix;
	}
};

#endif // ___Longest_Common_Prefix_14_h___