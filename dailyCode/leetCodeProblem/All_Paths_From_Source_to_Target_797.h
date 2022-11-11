#ifndef ___All_Paths_From_Source_to_Target_797_h___
#define ___All_Paths_From_Source_to_Target_797_h___
/*
797. ___All_Paths_From_Source_to_Target_797_h___
https://leetcode.com/problems/all-paths-from-source-to-target/
*/
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	void graph_traversal_dfs(vector<vector<int>>& graph, int idx, vector<int> path, vector<vector<int>>& result)
	{
		if (idx == graph.size() - 1)
		{
			result.push_back(path);
			return;
		}

		for (int index = 0; index < graph[idx].size(); index++)
		{
			path.push_back(graph[idx][index]);
			graph_traversal_dfs(graph, graph[idx][index], path, result);
			path.pop_back();
		}
		;
	}
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> result;
		vector<int> path;
		path.push_back(0);
		graph_traversal_dfs(graph, 0, path, result);
		return result;
	}
};

#endif