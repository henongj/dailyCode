
//https://leetcode.com/problems/course-schedule-ii/
//210. Course Schedule II
#ifndef ___Course_Schedule_II_With_BFS_210_h___
#define ___Course_Schedule_II_With_BFS_210_h___
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
using namespace std;
class Solution {
public:
	// topologhical sort with BFS
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

		vector<int> result;
		vector<int> inDegree(numCourses, 0);
		// graph[i]'s element means that want to take i, you must take graph[i]'s element first
		vector<vector<int>> graph(numCourses, vector<int>());
		queue<int> q;
		// want to take p[0], must already take p[1]
		for (auto& pre : prerequisites) {
			graph[pre[1]].push_back(pre[0]);
			inDegree[pre[0]]++;
		}

		for (int i = 0; i < numCourses; i++) {
			if (inDegree[i] == 0)
				q.push(i);
		}

		while (!q.empty()) {
			int current = q.front();
			q.pop();
			result.push_back(current);
			for (int next = 0; next < graph[current].size(); next++)
			{ // 이 원소가 선행되어야 하는 원소들의 진입차수를 줄인다
				inDegree[graph[current][next]]--;
				if (inDegree[graph[current][next]] == 0)
					q.push(graph[current][next]);
			}
		}

		if (result.size() != numCourses)
			return vector<int>();
		return result;

	}
};



#endif // ___Course_Schedule_II_h_210___
