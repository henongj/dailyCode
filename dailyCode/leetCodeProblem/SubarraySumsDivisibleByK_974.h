
//https://leetcode.com/problems/subarray-sums-divisible-by-k/
//974. Subarray Sums Divisible by K
#ifndef ___SubarraySumsDivisibleByK_974_h___
#define ___SubarraySumsDivisibleByK_974_h___
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
	int subarraysDivByK(vector<int>& nums, int k) {
		int nSize = nums.size();
		int nSum = 0;
		int nCount = 0;
		vector<int> vRemainder(k, 0);
		vRemainder[0] = 1;

		for (int i = 0; i < nSize; i++) {
			nSum += nums[i];
			int nRemainder = nSum % k;
			if (nRemainder < 0) {
				nRemainder += k;
			}
			nCount += vRemainder[nRemainder];
			vRemainder[nRemainder]++;
		}
		return nCount;
	}
};
#endif // !___SubarraySumsDivisibleByK_974_h___