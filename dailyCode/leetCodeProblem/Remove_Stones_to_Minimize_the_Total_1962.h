
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
		// 가장 큰 값을 계속 도출
		for (int i = 0; i < piles.size(); i++)
		{
			sum += piles[i];
			pq.push(piles[i]);
		}

		while (k > 0)
		{
			// 가장 큰 값을 반타작하면서 sum 값을 갱신
			int t = pq.top();
			pq.pop();
			sum -= t;
			t & 1 ? t = t / 2 + 1 : t = t / 2;
			sum += t;
			pq.push(t);
			k--;
		}
		//반환
		return sum;

	}
};

#endif /* ___Remove_Stones_to_Minimize_the_Total_1962_h___ */