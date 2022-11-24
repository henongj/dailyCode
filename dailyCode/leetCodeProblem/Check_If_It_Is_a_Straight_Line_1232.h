

//https://leetcode.com/problems/check-if-it-is-a-straight-line/?envType=study-plan&id=programming-skills-i
//1232. Check If It Is a Straight Line
#ifndef ___Check_If_It_Is_a_Straight_Line_1232_h___
#define ___Check_If_It_Is_a_Straight_Line_1232_h___

#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;
class Solution {
public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		if (coordinates.size() == 2)
			return true;
		int x1 = coordinates[0][0]; int y1 = coordinates[0][1];
		int x2 = coordinates[1][0]; int y2 = coordinates[1][1];
		int dx = x2 - x1;
		int dy = y2 - y1;
		for (int i = 2; i < coordinates.size(); i++) {
			int x = coordinates[i][0];
			int y = coordinates[i][1];
			if (dx * (y - y1) != dy * (x - x1))
				return false;
		}
		return true;

	}
};
/* testcase
[[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
[[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
[[0,0],[0,1],[0,-1]]
*/
#endif // ___Check_If_It_Is_a_Straight_Line_1232_h___

