//https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
//1443. Minimum Time to Collect All Apples in a Tree
#ifndef ___Minimum_Time_to_Collect_All_Apples_in_a_Tree_1443_h___
#define ___Minimum_Time_to_Collect_All_Apples_in_a_Tree_1443_h___
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
#include<cmath>	
using namespace std;
class Solution {
public:
	int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
		vector<vector<int>> graph(n);
		for (auto& edge : edges) {
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		return dfs(graph, hasApple, 0, -1);
	}
	int dfs(vector<vector<int>>& graph, vector<bool>& hasApple, int node, int parent) {
		int ans = 0;
		for (int child : graph[node]) {
			if (child != parent) {
				ans += dfs(graph, hasApple, child, node);
			}
		}
		if (ans > 0 || hasApple[node]) {
			ans += 2;
		}
		return ans;
	}
};
#endif // ___Minimum_Time_to_Collect_All_Apples_in_a_Tree_1443_h___