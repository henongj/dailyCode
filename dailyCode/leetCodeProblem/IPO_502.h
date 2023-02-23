#pragma once
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
#include<set>
using namespace std;

// https://leetcode.com/problems/ipo/
//502. IPO
class Solution {
public:
	int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
		int n = profits.size();
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			v.push_back({ capital[i], profits[i] });
		}
		sort(v.begin(), v.end());
		priority_queue<int> pq;
		int i = 0;
		while (k--) {
			while (i < n && v[i].first <= w) {
				pq.push(v[i].second);
				i++;
			}
			if (pq.empty()) {
				break;
			}
			w += pq.top();
			pq.pop();
		}
		return w;
	}
};