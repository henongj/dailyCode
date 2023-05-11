#pragma once
#include<vector>

//https://leetcode.com/problems/uncrossed-lines/
class Solution {
public:
	int maxUncrossedLines(std::vector<int>& nums1, std::vector<int>& nums2) {
		int n = nums1.size(), m = nums2.size();
		std::vector<std::vector<int>> nCrossLine(n + 1, std::vector<int>(m + 1, 0));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (nums1[i - 1] == nums2[j - 1])
					nCrossLine[i][j] = nCrossLine[i - 1][j - 1] + 1;
				else
					nCrossLine[i][j] = std::max({ nCrossLine[i - 1][j], nCrossLine[i][j - 1] });
			}
		}
		return nCrossLine[n][m];
	}
};