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
#include<unordered_set>
using namespace std;

//https://leetcode.com/problems/best-team-with-no-conflicts/description/
//1626. Best Team With No Conflicts
class Solution {
public:
	int bestTeamScore(vector<int>& scores, vector<int>& ages) {
		int n = scores.size();
		vector<pair<int, int>> v;
		for (int i = 0; i < n; ++i) {
			v.push_back({ ages[i], scores[i] });
		}
		sort(v.begin(), v.end());
		vector<int> dp(n, 0);
		dp[0] = v[0].second;
		int res = dp[0];
		for (int i = 1; i < n; ++i) {
			dp[i] = v[i].second;
			for (int j = 0; j < i; ++j) {
				if (v[j].second <= v[i].second) {
					dp[i] = max(dp[i], dp[j] + v[i].second);
				}
			}
			res = max(res, dp[i]);
		}
		return res;
	}
};