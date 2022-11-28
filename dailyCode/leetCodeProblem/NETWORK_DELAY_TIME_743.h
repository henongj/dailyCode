
// https://leetcode.com/problems/network-delay-time/
//743. Network Delay Time
#ifndef ___NETWORK_DELAY_TIME_743_h___
#define ___NETWORK_DELAY_TIME_743_h___
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
using namespace std;

class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {

		// times[row][0] = 시작, times[row][1] = 도착, times[row][2] = 가중치
		// n = 노드 갯수 , k = 시작 노드
		int result = 0;
		int can_not_go = 10001;
		// K를 기준으로 도착 노드들의 가중치를 저장한다
		vector<int> distance(n + 1, can_not_go);

		distance[k] = 0;

		// 모든 노드를 순회하며, 가중치를 갱신한다
		for (int node = 0; node < n; node++) {
			for (int j = 0; j < times.size(); j++) {
				int start = times[j][0];
				int end = times[j][1];
				int weight = times[j][2];
				// 못 가는 곳이 아니면서 가중치가 더 작으면
				if (distance[start] != can_not_go && distance[start] + weight < distance[end])
					distance[end] = distance[start] + weight;
			}
		}

		// 가장 큰 가중치를 찾는다
		for (int i = 1; i < distance.size(); i++) {
			if (distance[i] == can_not_go)
				return -1;
			result = max(result, distance[i]);
		}
		return result;
	}
};

#endif // ___NETWORK_DELAY_TIME_743_h___
