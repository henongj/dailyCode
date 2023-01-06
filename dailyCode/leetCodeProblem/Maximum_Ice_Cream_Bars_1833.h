
//https://leetcode.com/problems/maximum-ice-cream-bars/
//1833. Maximum Ice Cream Bars
#ifndef ___Maximum_Ice_Cream_Bars_1833_h___
#define ___Maximum_Ice_Cream_Bars_1833_h___
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
#include<cmath>	
using namespace std;
class Solution {
public:
	int maxIceCream(vector<int>& costs, int coins) {
		sort(costs.begin(), costs.end());
		int ans = 0;
		for (int i = 0; i < costs.size(); i++) {
			if (coins >= costs[i]) {
				coins -= costs[i];
				ans++;
			}
			else {
				break;
			}
		}
		return ans;
	}
};
#endif // !___Maximum_Ice_Cream_Bars_1833_h___
