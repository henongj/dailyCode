
//https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
//1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
#ifndef ___FIND_THE_CITY_WITH_THE_SMALLEST_NUMBER_OF_NEIGHBORS_AT_A_THRESHOLD_DISTANCE_1334_h___
#define ___FIND_THE_CITY_WITH_THE_SMALLEST_NUMBER_OF_NEIGHBORS_AT_A_THRESHOLD_DISTANCE_1334_h___
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
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
		
		// edges[row][0] = 시작, edges[row][1] = 도착, edges[row][2] = 가중치
		vector<vector<int>> graph(n, vector<int>(n, 10001));

		// 자기 자신에게 가는 비용은 0이다
		for (int i = 0; i < n; i++) {
			graph[i][i] = 0;
		}
		// 다른 지점으로 가기 위한 비용을 입력한다
		for (auto& edge : edges) {
			graph[edge[0]][edge[1]] = edge[2];
			graph[edge[1]][edge[0]] = edge[2];
		}

		// 플로이드 와샬 알고리즘을 이용하여 모든 지점간의 최단 거리를 구한다
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
		
		int minCity = -1;
		int minCount = INT_MAX;
		// 모든 지점을 순회하며, distanceThreshold 이하의 지점의 개수를 구한다
		for (int i = 0; i < n; i++) {
			int count = 0;
			for (int j = 0; j < n; j++) {
				if (graph[i][j] <= distanceThreshold) {
					count++;
				}
			}
			if (count <= minCount) {
				minCount = count;
				minCity = i;
			}
		}
		// 
		return minCity;
	}

};

#endif