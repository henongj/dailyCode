
//https://leetcode.com/problems/coin-change-ii/?envType=study-plan&id=dynamic-programming-i
//518. Coin Change 2
#ifndef ___Coin_Change_2_518_h___
#define ___Coin_Change_2_518_h___
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
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < coins.size(); i++) {
			for (int j = coins[i]; j <= amount; j++) {
				dp[j] += dp[j - coins[i]];
			}
		}
		return dp[amount];
	}
};
#endif //___Coin_Change_2_518_h___
