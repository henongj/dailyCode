
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/?envType=study-plan&id=dynamic-programming-i
//714. Best Time to Buy and Sell Stock with Transaction Fee
#ifndef ___Best_Time_to_Buy_and_Sell_Stock_with_Transaction_Fee_714_h___
#define ___Best_Time_to_Buy_and_Sell_Stock_with_Transaction_Fee_714_h___
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
	int maxProfit(vector<int>& prices, int fee) {
		int n = prices.size();
		vector<int> buy(n, 0);
		vector<int> sell(n, 0);
		buy[0] = -prices[0];
		for (int i = 1; i < n; i++) {
			buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
			sell[i] = max(sell[i - 1], buy[i - 1] + prices[i] - fee);
		}
		return sell[n - 1];
	}
};
#endif // ___Best_Time_to_Buy_and_Sell_Stock_with_Transaction_Fee_714_h___