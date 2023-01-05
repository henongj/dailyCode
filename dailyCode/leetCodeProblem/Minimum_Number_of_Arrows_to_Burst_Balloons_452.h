
//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
//452. Minimum Number of Arrows to Burst Balloons
#ifndef ___Minimum_Number_of_Arrows_to_Burst_Balloons_452_h___
#define ___Minimum_Number_of_Arrows_to_Burst_Balloons_452_h___
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

class Solution {
public:
	// time limit solution, i can't figure out why
	int findMinArrowShots_TLE(vector<vector<int>>& points) {
		int n = points.size();
		if (n == 0)
			return 0;
		sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {return a[1] < b[1]; });
		int count = 1;
		int end = points[0][1];
		for (int i = 1; i < n; i++)
		{
			if (points[i][0] > end)
			{
				count++;
				end = points[i][1];
			}
		}
		return count;
	}
	static bool comp(vector<int>& a, vector<int>& b)
	{
		return a[1] < b[1];
	}
	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.size() == 0)
			return 0;

		sort(points.begin(), points.end(), comp);

		int arrows = 1;
		int last = points[0][1];

		for (int i = 1; i < points.size(); i++)
		{
			if (points[i][0] > last)
			{
				arrows++;
				last = points[i][1];
			}
		}
		return arrows;
	}
};
#endif //___Minimum_Number_of_Arrows_to_Burst_Balloons_452_h___