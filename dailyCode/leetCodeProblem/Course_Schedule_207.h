
// 207. Course Schedule
//https://leetcode.com/problems/course-schedule/
#ifndef ___Course_Schedule_207_h___
#define ___Course_Schedule_207_h___
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
	void graph_traversal(const vector<vector<int>>& can_course, const vector<vector<int>>& must_coursed, vector<bool>& visited, int target)
	{
		if (visited[target])
			return;

		// must_coursed 가 전부 visited에서 방문했어야 (트루여야) 수강 가능
		for (int i = 0; i < must_coursed[target].size(); ++i)
		{
			if (!visited[must_coursed[target][i]])
				return;
		}

		visited[target] = true;

		for (int idx = 0; idx < can_course[target].size(); idx++)
		{
			graph_traversal(can_course, must_coursed, visited, can_course[target][idx]);
		}

	}
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> can_course(numCourses, vector<int>());
		vector<vector<int>> must_coursed(numCourses, vector<int>());
		vector<bool> visited(numCourses, false);

		for (int i = 0; i < prerequisites.size(); ++i)
		{
			can_course[prerequisites[i][0]].push_back(prerequisites[i][1]);
			must_coursed[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}

		for (int i = 0; i < numCourses; ++i)
			graph_traversal(can_course, must_coursed, visited, i);

		for (int i = 0; i < numCourses; ++i)
		{
			if (!visited[i])
				return false;
		}


		return true;
	}
};

#endif