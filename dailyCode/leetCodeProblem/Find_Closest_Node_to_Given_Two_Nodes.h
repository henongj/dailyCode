
//https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
//2359. Find Closest Node to Given Two Nodes
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
#include<set>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int closestMeetingNode(vector<int>& edges, int node1, int node2) {
		unordered_map<int, vector<int>> graph;
		for (int i = 0; i < edges.size(); i += 2) {
			graph[edges[i]].push_back(edges[i + 1]);
			graph[edges[i + 1]].push_back(edges[i]);
		}
		unordered_set<int> visited;
		queue<pair<int, int>> q;
		q.push({ node1, 0 });
		visited.insert(node1);
		while (!q.empty()) {
			auto [node, dist] = q.front();
			q.pop();
			if (node == node2) return dist;
			for (auto& neighbor : graph[node]) {
				if (visited.count(neighbor)) continue;
				visited.insert(neighbor);
				q.push({ neighbor, dist + 1 });
			}
		}
		return -1;
	}
};