//https://leetcode.com/problems/redundant-connection/
//684. Redundant Connection
#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;
#ifndef ___Redundant_Connection_684_h___
#define ___Redundant_Connection_684_h___

class Solution {
public:
	int find(vector<int>& parent, int& edge)
	{
		if (parent[edge] == edge)
			return edge;
		return find(parent, parent[edge]);
	}
	void union_graph(vector<int>& parent, int& edge1, int& edge2)
	{
		int parent1 = find(parent, edge1);
		int parent2 = find(parent, edge2);
		if (parent1 != parent2)
			parent[parent1] = parent2;
	}
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> result;
		vector<int> parent(edges.size() + 1, 0);
		for (int i = 0; i < parent.size(); ++i)
			parent[i] = i; // �� �׷����� �ڽ��� �θ�� ��´�

		for (auto p : parent)
			cout << p << " ";
		for (int i = 0; i < edges.size(); ++i)
		{
			// �θ� ������ ����Ŭ�� ����� ���̴�
			// ����Ŭ�� ����� �ش� edge�� �����Ѵ�
			int parent1 = find(parent, edges[i][0]);
			int parent2 = find(parent, edges[i][1]);
			if (parent1 == parent2)
			{
				result.push_back(edges[i][0]);
				result.push_back(edges[i][1]);
				break;
			}
			else // ����Ŭ�� ������ union
				union_graph(parent, edges[i][0], edges[i][1]);
		}
		return result;
	}
};

#endif // ___Redundant_Connection_684_h___