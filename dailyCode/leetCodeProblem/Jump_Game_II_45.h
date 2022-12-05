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

#ifndef ___Jump_Game_II_45_h___
#define ___Jump_Game_II_45_h___
//https://leetcode.com/problems/jump-game-ii/?envType=study-plan&id=dynamic-programming-i
//45. Jump Game II
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
	int jump(vector<int>& nums) {
		int n = nums.size();
		int end = 0;
		int maxPosition = 0;
		int steps = 0;
		for (int i = 0; i < n - 1; i++) {
			maxPosition = max(maxPosition, i + nums[i]);
			if (i == end) {
				end = maxPosition;
				steps++;
			}
		}
		return steps;
	}
};
#endif // ___Jump_Game_II_45_h___