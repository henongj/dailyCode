// 547 ___Number_of_Provinces_547_h___
#ifndef ___Number_of_Provinces_547_h___
#define ___Number_of_Provinces_547_h___
// https://leetcode.com/problems/number-of-provinces/
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
class Solution {
public:
	int findCircleNum(vector<vector<int>>& isConnected) {
		vector<bool> visited(isConnected.size(), false);
		queue<int> q;
		int count = 0;
		for (int i = 0; i < isConnected.size(); i++) {
			if (!visited[i])
			{
				q.push(i);
				visited[i] = true;
				while (!q.empty()) {
					int node = q.front();
					q.pop();
					for (int next = 0; next < isConnected.size(); next++) {
						if (isConnected[node][next] == 1 && !visited[next]) 
						{
							q.push(next);
							visited[next] = true;
						}
					}
				}
				count++;
			}
		}
	}
	int findCircleNum2(vector<vector<int>>& isConnected) {
		vector<bool> visited(isConnected.size(), false);
		queue<int> q;
		int count = 0;
		for (int i = 0; i < isConnected.size(); i++) {
			if (!visited[i])
			{
				q.push(i);
				visited[i] = true;
				while (!q.empty()) {
					int node = q.front();
					q.pop();
					for (int next = 0; next < isConnected.size(); next++) {
						if (isConnected[node][next] == 1 && !visited[next]) {
							q.push(next);
							visited[next] = true;
						}
					}
				}
				count++;
			}
		}
		return count;
	}
};

#endif
