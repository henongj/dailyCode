
/*
1779. Find Nearest Point That Has the Same X or Y Coordinate
https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/?envType=study-plan&id=programming-skills-i


*/
#ifndef ___Find_Nearest_Point_That_Has_the_Same_X_or_Y_Coordinate_1779_h___
#define ___Find_Nearest_Point_That_Has_the_Same_X_or_Y_Coordinate_1779_h___

/* testCase
x, y : 3 4
[[1,2],[3,1],[2,4],[2,3],[4,4]]
*/

class Solution {
public:
	/*
	1. ��ȿ�� ��ǥ���� �����Ѵ�. �ش� ���� ��ȿ�ϴٸ�
		1.1 �� ���� ����ź �Ÿ��� ���Ѵ�
	2. ����ź �Ÿ��� ���� ��ǥ�� ���� �� ���� ����� ���� ã�´�.
	*/

	inline int get_manhattan_distance(vector<int> v1, vector<int> v2)
	{
		return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
	}

	inline bool is_vaild_position(const int& x, const int& y, const vector<int>& point)
	{
		return point[0] == x || point[1] == y;
	}

	int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
		int minimum_distance = INT_MAX;
		int index = INT_MAX;
		for (int i = 0; i < points.size(); i++)
		{
			if (is_vaild_position(x, y, points[i]))
			{
				vector<int> v = { x,y };
				int distance = get_manhattan_distance(v, points[i]);
				if (distance < minimum_distance)
				{
					minimum_distance = distance;
					index = i;
				}
			}
		}
		return minimum_distance == INT_MAX ? -1 : index;
	}
};

#endif

