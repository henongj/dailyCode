#ifndef ___Find_if_Path_Exists_in_Graph_1971_h___
#define ___Find_if_Path_Exists_in_Graph_1971_h___

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

	vector<vector<int>> adjacent_list(-1);
	auto visited = get_matrix(n);

	for (auto edge : edges)
	{
		adjacent_list[edge[0]].push_back(edge[1]);
		adjacent_list[edge[1]].push_back(edge[0]);
	}




}

#endif