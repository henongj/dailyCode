
//https://leetcode.com/problems/sum-of-distances-in-tree/description/
//834. Sum of Distances in Tree
#ifndef ___Sum_of_Distances_in_Tree_834_h___
#define ___Sum_of_Distances_in_Tree_834_h___
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
	void dfs(vector<vector<int>>& graph, int node, int parent, vector<int>& count, vector<int>& res) {
		for (int i = 0; i < graph[node].size(); i++) {
			int child = graph[node][i];
			if (child == parent) continue;
			dfs(graph, child, node, count, res);
			count[node] += count[child];
			res[node] += res[child] + count[child];
		}
	}
	void dfs2(vector<vector<int>>& graph, int node, int parent, vector<int>& count, vector<int>& res) {
		for (int i = 0; i < graph[node].size(); i++) {
			int child = graph[node][i];
			if (child == parent) continue;
			res[child] = res[node] - count[child] + count.size() - count[child];
			dfs2(graph, child, node, count, res);
		}
	}
	vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
		vector<vector<int>> graph(n);
		for (int i = 0; i < edges.size(); i++) {
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}
		vector<int> count(n, 1);
		vector<int> res(n, 0);
		dfs(graph, 0, -1, count, res);
		dfs2(graph, 0, -1, count, res);
		return res;

	}
};
#endif // ___Sum_of_Distances_in_Tree_834_h___
