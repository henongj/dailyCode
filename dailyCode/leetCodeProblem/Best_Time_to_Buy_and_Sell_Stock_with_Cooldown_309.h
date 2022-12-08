//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/?envType=study-plan&id=dynamic-programming-i
//309. Best Time to Buy and Sell Stock with Cooldown
#ifndef ___309__Best_Time_to_Buy_and_Sell_Stock_with_Cooldown_309_h___
#define ___309__Best_Time_to_Buy_and_Sell_Stock_with_Cooldown_309_h___
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
		int n = prices.size();
		if (n == 0) return 0;
		vector<int> buy(n, 0);
		vector<int> sell(n, 0);
		buy[0] = -prices[0];
		for (int i = 1; i < n; i++) {
			buy[i] = max(buy[i - 1], (i >= 2 ? sell[i - 2] : 0) - prices[i]);
			sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
		}
		return sell[n - 1];
	}
};
#endif // ___309__Best_Time_to_Buy_and_Sell_Stock_with_Cooldown_309_h___