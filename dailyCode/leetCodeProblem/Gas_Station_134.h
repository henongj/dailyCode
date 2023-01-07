//https://leetcode.com/problems/gas-station/description/
//134. Gas Station
#ifndef ___Gas_Station_134_h___
#define ___Gas_Station_134_h___
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
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		int ans = 0;
		int sum = 0;
		int total = 0;
		for (int i = 0; i < n; i++) {
			sum += gas[i] - cost[i];
			total += gas[i] - cost[i];
			if (sum < 0) {
				ans = i + 1;
				sum = 0;
			}
		}
		return total >= 0 ? ans : -1;
	}
};
#endif // ___Gas_Station_134_h___

