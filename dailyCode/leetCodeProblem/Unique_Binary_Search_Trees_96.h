
//https://leetcode.com/problems/unique-binary-search-trees/description/?envType=study-plan&id=dynamic-programming-i
//96. Unique Binary Search Trees
#ifndef ___Unique_Binary_Search_Trees_96_h___
#define ___Unique_Binary_Search_Trees_96_h___
// catalan number에 대해 알 필요가 있음

class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}
		return dp[n];
	}
};
#endif// ___Unique_Binary_Search_Trees_96_h___