
//https://leetcode.com/problems/edit-distance/?envType=study-plan&id=dynamic-programming-i
//72. Edit Distance
#ifndef ___Edit_Distance_72_h___
#define ___Edit_Distance_72_h___
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
    int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i <= m; ++i) {
			dp[i][0] = i;
		}
		for (int j = 0; j <= n; ++j) {
			dp[0][j] = j;
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				}
			}
		}
		return dp[m][n];
    }
};
#endif // ___Edit_Distance_72_h___