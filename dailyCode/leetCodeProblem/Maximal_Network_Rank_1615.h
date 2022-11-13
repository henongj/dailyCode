#ifndef ___Maximal_Network_Rank_1615_h___
#define ___Maximal_Network_Rank_1615_h___

/*
1615.
___Maximal_Network_Rank_1615_h___
https://leetcode.com/problems/maximal-network-rank
*/
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {

		vector<vector<int>> adj(n, vector<int>(n, 0));
		vector<int> edge_count(n, 0);

		int result = 0;

		for (int road = 0; road < roads.size(); road++)
		{
			//edge를 각 노드에 연결
			edge_count[roads[road][0]] += 1;
			edge_count[roads[road][1]] += 1;
			adj[roads[road][0]][roads[road][1]] = 1;
			adj[roads[road][1]][roads[road][0]] = 1;

		}

		for (int node1 = 0; node1 < n; node1++)
		{
			for (int node2 = node1 + 1; node2 < n; node2++)
			{
				int sum = edge_count[node1] + edge_count[node2];
				if (adj[node1][node2] == 1) // 서로 연결되어 있으면
					sum = sum - 1;
				result = max(result, sum);
			}
		}

		return result;

	}
};

#endif // !___Maximal_Network_Rank_1615_h___

