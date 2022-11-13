#ifndef ___graph_implement_adjacency_h___
#define ___graph_implement_adjacency_h___

/*

0 -> 1, 2, 3
1 -> 0, 2
2 -> 0, 1, 3
3 -> 0, 3

*/
// ajacency matrix
// ajacency list
#include<vector>
#include<iostream>
using namespace std;
vector<vector<int>> adjcency_list = {
	{1, 2, 3}, // 0 과 연결된 노드
	{0, 2},// 1 과 연결된 노드
	{0, 1, 3}, // 2 와 연결된 노드
	{0, 2}, // 3 와 연결된 노드
};

int ajacency_matrix[4][4] = {
	{0, 1, 1, 1},
	{1, 0, 1, 0},
	{1, 1, 0, 1},
	{1, 0, 1, 0},
};

void BFS_traversal_adjacency_list(vector<vector<int>>& adjacency_list)
{
	int len = adjacency_list.size();
	vector<bool> visited(adjacency_list.size(), false);
	queue<int> q;

	q.push(0);
	visited[0] = true;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		cout << node << " ";
		for (int idx = 0; idx < adjacency_list[node].size(); idx++)
		{
			int next = adjacency_list[node][idx];
			if (!visited[next])
			{
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

void DFS_traversal_adjacency_list(vector<vector<int>>& adjacency_list,
	vector<bool>& visited, int target)
{
	if (visited[target])
		return;

	visited[target] = true;
	cout << target << " ";

	for (int idx = 0; idx < adjacency_list[target].size(); idx++)
	{
		int next = adjacency_list[target][idx];
		if (!visited[next])
		{
			DFS_traversal_adjacency_list(adjacency_list, visited, next);
		}
	}
}

void BFS_traversal_adjacency_matrix(int* adjacency_matrix[4])
{
	// 행렬의 길이 (column)
	int len = sizeof(adjacency_matrix) / sizeof(adjacency_matrix[0]);

	vector<bool> visited(len, false);
	queue<int> q;

	q.push(0);
	visited[0] = true;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		cout << node << " ";
		for (int idx = 0; idx < len; idx++)
		{
			if (adjacency_matrix[node][idx] == 1 && !visited[idx])
			{
				q.push(idx);
				visited[idx] = true;
			}
		}
	}
}

void DFS_traversal_adjacency_matrix(int* adjacency_matrix[4],
	vector<bool>& visited, int target)
{
	if (visited[target])
		return;

	visited[target] = true;
	cout << target << " ";

	for (int idx = 0; idx < 4; idx++)
	{
		int next = adjacency_matrix[target][idx];
		if (!visited[next])
		{
			DFS_traversal_adjacency_matrix(adjacency_matrix, visited, next);
		}
	}
}
#endif