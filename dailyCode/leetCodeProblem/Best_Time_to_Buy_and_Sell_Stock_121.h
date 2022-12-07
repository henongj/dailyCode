//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=study-plan&id=dynamic-programming-i
//121. Best Time to Buy and Sell Stock
#ifndef ___Best_Time_to_Buy_and_Sell_Stock_121_h___
#define ___Best_Time_to_Buy_and_Sell_Stock_121_h___
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
		int minPrice = INT_MAX;
		int maxProfit = 0;
		for (int i = 0; i < prices.size(); i++) {
			if (prices[i] < minPrice) {
				minPrice = prices[i];
			}
			else if (prices[i] - minPrice > maxProfit) {
				maxProfit = prices[i] - minPrice;
			}
		}
		return maxProfit;
	}
};
#endif //___Best_Time_to_Buy_and_Sell_Stock_121_h___
