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
#include<numeric>
using namespace std;
//https://leetcode.com/problems/shuffle-the-array/
//1470. Shuffle the Array
class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		vector<int> res;
		for (int i = 0; i < n; i++) {
			res.push_back(nums[i]);
			res.push_back(nums[i + n]);
		}
		return res;
	}
};
