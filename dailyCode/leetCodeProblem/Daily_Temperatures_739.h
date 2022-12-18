
//https://leetcode.com/problems/daily-temperatures/
//739. Daily Temperatures
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

#ifndef ___Daily_Temperatures_739_h___
#define ___Daily_Temperatures_739_h___

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> res(temperatures.size(), 0);
		stack<int> s;
		for (int i = 0; i < temperatures.size(); i++) {
			while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
				res[s.top()] = i - s.top();
				s.pop();
			}
			s.push(i);
		}
		return res;
	}
};
#endif // _Daily_Temperatures_739_h___