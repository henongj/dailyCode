
//https://leetcode.com/problems/insert-interval/
//57. Insert Interval
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
using namespace std;

#ifndef ___Insert_Interval_57_h___
#define ___Insert_Interval_57_h___
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> res;
		int i = 0;
		while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
			res.push_back(intervals[i]);
			i++;
		}
		while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
			newInterval[0] = min(newInterval[0], intervals[i][0]);
			newInterval[1] = max(newInterval[1], intervals[i][1]);
			i++;
		}

		res.push_back(newInterval);
		while (i < intervals.size()) {
			res.push_back(intervals[i]);
			i++;
		}
		return res;
	}
};
#endif // ___Insert_Interval_57_h___
