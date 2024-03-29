#ifndef ___Find_if_Path_Exists_in_Graph_1971_h___
#define ___Find_if_Path_Exists_in_Graph_1971_h___

//1971. Find if Path Exists in Graph
//https://leetcode.com/problems/find-if-path-exists-in-graph/
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:

	bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
		vector<int> neighbors[n];
		for (auto edge : edges) { // ����
			neighbors[edge[0]].push_back(edge[1]);
			neighbors[edge[1]].push_back(edge[0]);
		}
		vector<bool> visited(n, false);
		
		queue<int> q;
		q.push(source);
		visited[source] = true;

		while(!q.empty())
		{
			int target = q.front();
			q.pop();
			
			if (target == destination)
				return true;
			else
			{
				for (auto adjacent : neighbors[target])
				{
					if (!visited[adjacent])
					{
						q.push(adjacent);
						visited[adjacent] = true;
					}
				}
			}
		}
		return false;
	}
};


class Solution2 {
public:
	bool find_path_dfs(vector<vector<int>>& adjacent_list, vector<vector<bool>>& visited, int source, int destination)
	{
		if (source == destination)
			return true;

		visited[source][destination] = true;
		for (auto node : adjacent_list[source])
		{
			if (!visited[source][node])
			{
				if (find_path_dfs(adjacent_list, visited, node, destination))
					return true;
			}
		}
		return false;
	}
	bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
		vector<vector<int>> adjacent_list;
		vector<vector<bool>> visited;
		for (int i = 0; i < n; i++)
		{
			vector<int> v;
			vector<bool> b;
			for (int i = 0; i < n; i++)
			{
				v.push_back(-1);
				b.push_back(false);
			}
			adjacent_list.push_back(v);
			visited.push_back(b);
		}

		for (auto edge : edges)
		{
			adjacent_list[edge[0]].push_back(edge[1]);
			adjacent_list[edge[1]].push_back(edge[0]);
		}
		return find_path_dfs(adjacent_list, visited, source, destination);
	}
};

#endif