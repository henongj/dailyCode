
//https://leetcode.com/problems/redundant-connection-ii/
//685. Redundant Connection II 
#ifndef ___Redundant_Connection_II_685_h___
#define ___Redundant_Connection_II_685_h___
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
	int find(vector<int>& parent, int edge)
	{
		if (parent[edge] == -1)
			return edge;
		return parent[edge] = find(parent, parent[edge]);
	}
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		vector<int> parent(n + 1, -1);
		vector<int> candA, candB;
		for (auto& edge : edges)
		{
			if (parent[edge[1]] == -1)
				parent[edge[1]] = edge[0];
			else
			{
				candA = { parent[edge[1]], edge[1] };
				candB = edge;
				edge[1] = 0;
			}
		}
		for (int i = 0; i <= n; ++i)
			parent[i] = -1;
		for (auto& edge : edges)
		{
			if (edge[1] == 0)
				continue;
			int u = find(parent, edge[0]);
			int v = find(parent, edge[1]);
			if (u == v)
			{
				if (candA.empty())
					return edge;
				else
					return candA;
			}
			parent[v] = u;

		}
		return candB;

	}
};
/*
testcase
[[2,1],[3,1],[4,2],[1,4]] // [2,1]
[[1,2],[1,3],[2,3]]
[[1,2],[2,3],[3,4],[4,1],[1,5]]
*/

#endif // ___Redundant_Connection_II_685_h___