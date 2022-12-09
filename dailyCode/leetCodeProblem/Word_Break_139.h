
//https://leetcode.com/problems/word-break/?envType=study-plan&id=dynamic-programming-i
//139. Word Break
#ifndef ___Word_Break_139_h___
#define ___Word_Break_139_h___
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
	bool wordBreak(string s, vector<string>& wordDict) {
		int n = s.size();
		vector<bool> dp(n + 1, false);
		dp[0] = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[n];
	}
};
#endif // ___Word_Break_139_h___