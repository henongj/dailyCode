
#ifndef ___Non-decreasing_Subsequences_491_h___
#define ___Non-decreasing_Subsequences_491_h___
//https://leetcode.com/problems/non-decreasing-subsequences/
//491. Non-decreasing Subsequences
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
#include<set>
#include<unordered_set>
using namespace std;
class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {

		vector<vector<int>> result;
		vector<int> subsequence;
		dfs(nums, 0, subsequence, result);
		return result;
	}
	void dfs(const vector<int>& nums, int start, vector<int>& subsequence, vector<vector<int>>& result) {
		if (subsequence.size() >= 2) {
			result.push_back(subsequence);
		}
		unordered_set<int> used;
		for (int i = start; i < nums.size(); ++i) {
			if (used.find(nums[i]) != used.end()) {
				continue;
			}
			if (subsequence.empty() || nums[i] >= subsequence.back()) {
				subsequence.push_back(nums[i]);
				used.insert(nums[i]);
				dfs(nums, i + 1, subsequence, result);
				subsequence.pop_back();
			}
		}
	}
};
#endif // ___Non-decreasing_Subsequences_491_h___
