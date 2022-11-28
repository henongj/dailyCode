
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

		// times[row][0] = ����, times[row][1] = ����, times[row][2] = ����ġ
		// n = ��� ���� , k = ���� ���
		int result = 0;
		int can_not_go = 10001;
		// K�� �������� ���� ������ ����ġ�� �����Ѵ�
		vector<int> distance(n + 1, can_not_go);

		distance[k] = 0;

		// ��� ��带 ��ȸ�ϸ�, ����ġ�� �����Ѵ�
		for (int node = 0; node < n; node++) {
			for (int j = 0; j < times.size(); j++) {
				int start = times[j][0];
				int end = times[j][1];
				int weight = times[j][2];
				// �� ���� ���� �ƴϸ鼭 ����ġ�� �� ������
				if (distance[start] != can_not_go && distance[start] + weight < distance[end])
					distance[end] = distance[start] + weight;
			}
		}

		// ���� ū ����ġ�� ã�´�
		for (int i = 1; i < distance.size(); i++) {
			if (distance[i] == can_not_go)
				return -1;
			result = max(result, distance[i]);
		}
		return result;
	}
};

#endif // ___NETWORK_DELAY_TIME_743_h___
