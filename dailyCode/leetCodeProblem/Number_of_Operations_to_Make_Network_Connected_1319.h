
//https://leetcode.com/problems/number-of-operations-to-make-network-connected/
//1319. Number of Operations to Make Network Connected
#ifndef ___Number_of_Operations_to_Make_Network_Connected_1319_h___
#define ___Number_of_Operations_to_Make_Network_Connected_1319_h___
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
		if (parent[edge] == edge)
			return edge;
		return parent[edge] = find(parent, parent[edge]);
	}
	int union_graph(vector<int>& parent, int& edge1, int& edge2)
	{
		int parent1 = find(parent, edge1);
		int parent2 = find(parent, edge2);
		if (parent1 != parent2)
		{
			if (parent1 < parent2)
				parent[parent2] = parent1;
			if (parent2 < parent1)
				parent[parent1] = parent2;
			return 1;
		}
		return 0;
	}
	int makeConnected(int n, vector<vector<int>>& connections) {
		// count how many root to use union find
		int cable = connections.size();
		if (cable < n - 1)
			return -1;

		unordered_map<int, int> root_vertexes;
		vector<int> parents(n, 0);
		for (int idx = 0; idx < parents.size(); idx++)
			parents[idx] = idx;

		for (auto edges : connections)
		{
			int parent1 = find(parents, edges[0]);
			int parent2 = find(parents, edges[1]);
			if (parent1 == parent2) // 사이클이 있으면 패스
				continue;
			else // 사이클이 없으면 union
				union_graph(parents, edges[0], edges[1]);
		}
		for (int idx = 0; idx < parents.size(); idx++)
			parents[idx] = find(parents, idx);

		for (auto parent : parents)
			cout << parent << " ";

		for (auto parent : parents)
			root_vertexes[parent] = parent;

		return root_vertexes.size() - 1;
	}
};
/*
5
[[0,1],[0,2],[3,4],[2,3]]
*/
#endif // 1319. Number of Operations to Make Network Connected