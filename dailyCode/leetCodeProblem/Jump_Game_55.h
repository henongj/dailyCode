
//https://leetcode.com/problems/jump-game/?envType=study-plan&id=dynamic-programming-i
//55. Jump Game
#ifndef ___Jump_Game_55_h___
#define ___Jump_Game_55_h___
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
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int maxPos = 0;
		for (int i = 0; i < n; i++) {
			if (i <= maxPos) {
				maxPos = max(maxPos, i + nums[i]);
				if (maxPos >= n - 1) {
					return true;
				}
			}
		}
		return false;
	}
};
#endif // ___Jump_Game_55_h___