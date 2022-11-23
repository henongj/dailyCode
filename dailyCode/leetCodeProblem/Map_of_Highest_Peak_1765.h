
//https://leetcode.com/problems/map-of-highest-peak/
// 1765. Map of Highest Peak

#ifndef ___Map_of_Highest_Peak_1765_h___
#define ___Map_of_Highest_Peak_1765_h___
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
	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		queue<pair<int, int>> q;
		vector<vector<int>> result = isWater;

		// 수원지 입력 받기
		for (int row = 0; row < isWater.size(); row++) {
			for (int col = 0; col < isWater[0].size(); col++) {
				if (isWater[row][col] == 1) {
					q.push(make_pair(row, col));
					result[row][col] = 0;
				}
				else {
					result[row][col] = -1;
				}
			}
		}

		// 퍼뜨리기
		while (!q.empty())
		{
			pair<int, int> cur = q.front();
			q.pop();
			int row = cur.first;
			int col = cur.second;
			// 상
			if (row - 1 >= 0 && result[row - 1][col] == -1) {
				result[row - 1][col] = result[row][col] + 1;
				q.push({ row - 1, col });
			}
			// 하
			if (row + 1 < isWater.size() && result[row + 1][col] == -1) {
				result[row + 1][col] = result[row][col] + 1;
				q.push({ row + 1, col });
			}
			// 좌
			if (col - 1 >= 0 && result[row][col - 1] == -1) {
				result[row][col - 1] = result[row][col] + 1;
				q.push({ row, col - 1 });
			}
			// 우
			if (col + 1 < isWater[0].size() && result[row][col + 1] == -1) {
				result[row][col + 1] = result[row][col] + 1;
				q.push({ row, col + 1 });
			}

		}
		return result;
	}
};
#endif