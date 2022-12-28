
//https://leetcode.com/problems/remove-stones-to-minimize-the-total/
// 1962. Remove Stones to Minimize the Total
#ifndef ___Remove_Stones_to_Minimize_the_Total_1962_h___
#define ___Remove_Stones_to_Minimize_the_Total_1962_h___
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
#include<stack>
using namespace std;
class Solution {
public:
	int minStoneSum(vector<int>& piles, int k) {

		int sum = 0;
		priority_queue<int> pq;
		// ���� ū ���� ��� ����
		for (int i = 0; i < piles.size(); i++)
		{
			sum += piles[i];
			pq.push(piles[i]);
		}

		while (k > 0)
		{
			// ���� ū ���� ��Ÿ���ϸ鼭 sum ���� ����
			int t = pq.top();
			pq.pop();
			sum -= t;
			t & 1 ? t = t / 2 + 1 : t = t / 2;
			sum += t;
			pq.push(t);
			k--;
		}
		//��ȯ
		return sum;

	}
};

#endif /* ___Remove_Stones_to_Minimize_the_Total_1962_h___ */