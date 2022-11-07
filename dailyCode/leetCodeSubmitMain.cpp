#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
#include"dataStruct/graph_traversal.h"
using namespace std;

vector<vector<bool>> get_matrix(int n)
{
	vector<vector<bool>> v;
	for (int i = 0; i < n; i++)
	{
		vector<bool> v1;
		for (int j = 0; j < n; j++)
		{
			v1.push_back(false);
		}
		v.push_back(v1);
	}
	return v;
}

class Solution {
public:
	

	
	bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

		vector<vector<int>> adjacent_list(-1);
		auto visited = get_matrix(n);
		
		for (auto edge : edges)
		{
			adjacent_list[ edge[0] ].push_back(edge[1]);
			adjacent_list[ edge[1] ].push_back(edge[0]);
		}
		
		
		
		
	}
};
	
int main(void)
{
	test_depth_limited_search();
	return 0;
}
