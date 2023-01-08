
//https://leetcode.com/problems/max-points-on-a-line/
//149. Max Points on a Line
#ifndef ___Max_Points_on_a_Line_149_h___
#define ___Max_Points_on_a_Line_149_h___
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
	int maxPoints(vector<vector<int>>& points) {
		int n = points.size();

		if (n < 3)
			return n;
		int res = 0;

		for (int i = 0; i < n; i++) {
			int same = 1;
			int maxPoints = 0;
			unordered_map<double, int> m;
			for (int j = i + 1; j < n; j++) {
				if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
					same++;
					continue;
				}
				double k = points[i][0] == points[j][0] ? INT_MAX : 0.0 + (double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
				m[k]++;
				maxPoints = max(maxPoints, m[k]);
			}
			res = max(res, maxPoints + same);
		}
		return res;
	}
};
#endif // ___Max_Points_on_a_Line_149_h___
