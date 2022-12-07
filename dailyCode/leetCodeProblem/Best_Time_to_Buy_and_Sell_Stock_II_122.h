
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan&id=dynamic-programming-i
// 122. Best Time to Buy and Sell Stock II
#ifndef ___Best_Time_to_Buy_and_Sell_Stock_II_122_h___
#define ___Best_Time_to_Buy_and_Sell_Stock_II_122_h___
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
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] > prices[i - 1]) {
				profit += prices[i] - prices[i - 1];
			}
		}
		return profit;
	}
};
#endif // ___Best_Time_to_Buy_and_Sell_Stock_II_122_h___