
//https://leetcode.com/problems/coin-change/description/?envType=study-plan&id=dynamic-programming-i
//322. Coin Change
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

#ifndef ___Coin_Change_322_h___
#define ___Coin_Change_322_h___
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0) return 0;
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) {
			for (int j = 0; j < coins.size(); j++) {
				if (coins[j] <= i) {
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				}
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}
};
#endif //___Coin_Change_322_h___