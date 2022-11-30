
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



// https://leetcode.com/problems/course-schedule/
// 207. Course Schedule
#ifndef ___Course_Schedule_207_Topological_Sort_h___
#define ___Course_Schedule_207_Topological_Sort_h___
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<stack>
#include<sstream>
using namespace std;

class Solution2 {
public:
	// use topological sort with dfs
	bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
		// visited val 1 == visited
		visited[node] = 1;

		// visit all the neighbors to know if there is a cycle
		for (int i = 0; i < graph[node].size(); i++) {
			// if the neighbor is visited and not finished, then there is a cycle
			if (visited[graph[node][i]] == 1)
				return false;
			// if the neighbor is not visited, visit it
			if (visited[graph[node][i]] == 0) {
				if (!dfs(graph[node][i], graph, visited)) return false;
			}
		}

		// value 2 == there is no cycle
		visited[node] = 2;
		return true;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses, vector<int>());
		vector<int> visited(numCourses, 0);
		// want to take p[0], you must take to p[1]	
		for (auto p : prerequisites)
			graph[p[1]].push_back(p[0]);
		for (int i = 0; i < numCourses; i++) {
			if (!dfs(i, graph, visited)) return false;
		}
		return true;
	}
};
#endif // ___Course_Schedule_207_h___
