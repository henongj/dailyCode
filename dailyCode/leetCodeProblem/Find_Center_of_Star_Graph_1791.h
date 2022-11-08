#ifndef ___Find_Center_of_Star_Graph_1791_h___
#define ___Find_Center_of_Star_Graph_1791_h___
// https://leetcode.com/problems/find-center-of-star-graph/
// 1791  Find_Center_of_Star_Graph_1791
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int findCenter(vector<vector<int>>& edges) {
		int center = 0;
		int value = -1;
		unordered_map<int, int> edge_map;
		for (auto edge : edges)
		{
			if (!edge_map.count(edge[0])) // 없으면 추가
				edge_map[edge[0]] = 1;
			else
				edge_map[edge[0]] += 1; // 있으면 +1

			if(!edge_map.count(edge[1])) // 반대도 마찬가지
				edge_map[edge[1]] = 1;
			else
				edge_map[edge[1]] += 1;
		}
		
		for (auto edge : edge_map)
		{//맥스값을 가진 노드가 중심이다
			if (edge.second > value)
			{
				center = edge.first;
				value = edge.second;
			}
		}
		return center;
		
	};
};


#endif