#ifndef ___Find_the_Town_Judge_997_h___
#define ___Find_the_Town_Judge_997_h___
//997. ___Find_the_Town_Judge_997_h___
//https://leetcode.com/problems/find-the-town-judge/
#include<vector>
using namespace std;
class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		int most_trusted = 0;
		int judge = 1;

		vector<int> trustCount(n + 1, 0);
		for (auto count : trust)
		{
			trustCount[count[0]] = -1; // 누군가를 믿는다면 판사가 아님
			if (trustCount[count[1]] != -1) // 판사 후보는 신임을 받는다
			{
				trustCount[count[1]] += 1;
				if (most_trusted < trustCount[count[1]])
				{
					most_trusted = trustCount[count[1]];
					judge = count[1];
				}
			}
		}

		//판사는 모두의 신임을 받는다
		if (most_trusted != n - 1)
			return -1;
		//판사는 유일하다
		for (int i = 1; i < trustCount.size(); i++)
			if (trustCount[i] == most_trusted && judge != i)
				return -1;

		// 판사는 아무도 안 믿는다
		return trustCount[judge] == -1 ? -1 : judge;
	}
};
#endif