
//https://leetcode.com/problems/wiggle-subsequence/?envType=study-plan&id=dynamic-programming-i
//376. Wiggle Subsequence
#ifndef ___Wiggle_Subsequence_376_h___
#define ___Wiggle_Subsequence_376_h___
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
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<int> up(nums.size(), 1);
		vector<int> down(nums.size(), 1);
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] > nums[i - 1]) {
				up[i] = down[i - 1] + 1;
				down[i] = down[i - 1];
			}
			else if (nums[i] < nums[i - 1]) {
				down[i] = up[i - 1] + 1;
				up[i] = up[i - 1];
			}
			else {
				down[i] = down[i - 1];
				up[i] = up[i - 1];
			}
		}
		return max(up.back(), down.back());
	}
};
#endif // ___Wiggle_Subsequence_376_h___
