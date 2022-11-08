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
		for (auto edge : edges) { // ¿Œ¡¢
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


#endif