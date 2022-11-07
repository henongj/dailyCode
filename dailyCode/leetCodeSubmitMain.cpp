#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
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
			adjacent_list[ edge[0] ].push_back(edge[1]);
			adjacent_list[ edge[1] ].push_back(edge[0]);
		}
		return find_path_dfs(adjacent_list,visited,source,destination);
	}
};
	
int main(void)
{
	test_depth_limited_search();
	return 0;
}
