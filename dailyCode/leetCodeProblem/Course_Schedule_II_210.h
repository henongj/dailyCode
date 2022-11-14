
/*
// ___Course_Schedule_II_210_h___
//https://leetcode.com/problems/course-schedule-ii/
*/
#ifndef ___Course_Schedule_II_210_h___
#define ___Course_Schedule_II_210_h___

#include<vector>
#include<iostream>
#include<queue>
using namespace std;
class Solution {
public:
	void dfs(vector<vector<int>>& can_course, vector<vector<int>>& have_coursed, vector<bool>& visited, int course, vector<int>& result)
	{
		for (int i = 0; i < have_coursed[course].size(); i++)
		{
			// cours가 have coursed 안 한 것이 있으면 그것을 먼저 수강해야 함
			if (!visited[have_coursed[course][i]])
				return;
		}
		visited[course] = true;
		result.push_back(course);

		for (int i = 0; i < can_course[course].size(); i++)
		{
			if (!visited[can_course[course][i]])
				dfs(can_course, have_coursed, visited, can_course[course][i], result);
		}
	}
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> can_course(numCourses, vector<int>());
		vector<vector<int>> have_cursed(numCourses, vector<int>());
		for (auto pre : prerequisites)
		{
			// course[idx] 를 들으면 course[idx]의 element 수강가능 조건 만족
			can_course[pre[1]].push_back(pre[0]);
			// have_cursed[idx]는 element를 모두 들어야 수강 가능
			have_cursed[pre[0]].push_back(pre[1]);
		}
		for (int i = 0; i < numCourses; i++)
		{
			vector<bool> visited(numCourses, false);
			vector<int> result;
			for (int j = 0; j < numCourses; j++)
			{
				if (!visited[j])
					dfs(can_course, have_cursed, visited, j, result);
			}
			if (result.size() == numCourses)
				return result;
		}
		return vector<int>();
	}
};

#endif 
