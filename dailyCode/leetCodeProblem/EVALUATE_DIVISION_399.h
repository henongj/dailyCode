
// https://leetcode.com/problems/evaluate-division/
// 399. Evaluate Division
#ifndef ___EVALUATE_DIVISION_399_h___
#define ___EVALUATE_DIVISION_399_h___
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

	vector<double> calcEquation(vector<vector<string>>& equations,
		vector<double>& values, vector<vector<string>>& queries) {
		vector<double> result;

		// <string = key , vector<pair< next , weight >> 
		unordered_map<string, vector<pair<string, double>>> graphs;
		// queue pair<next, product sum of weight> 


		for (int idx = 0; idx < equations.size(); idx++)
		{ // a -> b (2) b->c (3)
			graphs[equations[idx][0]].push_back(make_pair(equations[idx][1], values[idx]));
			graphs[equations[idx][1]].push_back(make_pair(equations[idx][0], 1 / values[idx]));
		}

		for (int idx = 0; idx < queries.size(); idx++)
		{
			string start = queries[idx][0];
			string end = queries[idx][1];
			if (graphs.find(start) == graphs.end() || graphs.find(end) == graphs.end())
			{
				result.push_back(-1.0);
				continue;
			}
			if (start == end)
			{
				result.push_back(1.0);
				continue;
			}
			queue<pair<string, double>> q;
			q.push(make_pair(start, 1.0));
			unordered_map<string, bool> visited;
			visited[start] = true;
			bool isFind = false;
			while (!q.empty())
			{
				pair<string, double> cur = q.front();
				q.pop();
				if (cur.first == end)
				{
					result.push_back(cur.second);
					isFind = true;
					break;
				}
				for (int i = 0; i < graphs[cur.first].size(); i++)
				{
					if (visited.find(graphs[cur.first][i].first) == visited.end())
					{
						q.push(make_pair(graphs[cur.first][i].first, cur.second * graphs[cur.first][i].second));
						visited[graphs[cur.first][i].first] = true;
					}
				}
			}
			if (!isFind)
			{
				result.push_back(-1.0);
			}
		}

		return result;
	}
};
#endif 