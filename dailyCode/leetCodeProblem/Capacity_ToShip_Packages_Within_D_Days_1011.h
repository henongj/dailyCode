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
#include<numeric>
using namespace std;

//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
//1011. Capacity To Ship Packages Within D Days

class Solution {
public:
	int shipWithinDays(vector<int>& weights, int days) {
		int left = *max_element(weights.begin(), weights.end());
		int right = accumulate(weights.begin(), weights.end(), 0);
		while (left < right) {
			int mid = left + (right - left) / 2;
			int need = 1, cur = 0;
			for (int i = 0; i < weights.size() && need <= days; ++i) {
				if (cur + weights[i] > mid) {
					cur = 0;
					++need;
				}
				cur += weights[i];
			}
			if (need > days) left = mid + 1;
			else right = mid;
		}
		return left;
	}
};