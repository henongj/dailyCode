
//https://leetcode.com/problems/longest-common-subsequence/
//1143. Longest Common Subsequence
#ifndef ___Longest_Common_Subsequence_1143_h___
#define ___Longest_Common_Subsequence_1143_h___
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
using namespace std;
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int len1 = text1.size();
		int len2 = text2.size();

		vector<vector<int>> memo(len1, vector<int>(len2, 0));

		for (int i = 0; i < len1; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				if (text1[i] == text2[j])
				{
					if (i == 0 || j == 0)
						memo[i][j] = 1;
					else
						memo[i][j] = memo[i - 1][j - 1] + 1;
				}
				else
				{
					if (i == 0 && j == 0)
						memo[i][j] = 0;
					else if (i == 0)
						memo[i][j] = memo[i][j - 1];
					else if (j == 0)
						memo[i][j] = memo[i - 1][j];
					else
						memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
				}
			}
		}
		return memo[len1 - 1][len2 - 1];

	}
};
#endif // ___Longest_Common_Subsequence_1143_h___
