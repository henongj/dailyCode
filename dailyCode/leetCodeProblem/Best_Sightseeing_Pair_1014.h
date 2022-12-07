//https://leetcode.com/problems/best-sightseeing-pair/?envType=study-plan&id=dynamic-programming-i
//1014. Best Sightseeing Pair
#ifndef ___Best_Sightseeing_Pair_1014_h___
#define ___Best_Sightseeing_Pair_1014_h___
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
    int maxScoreSightseeingPair(vector<int>& values) {
        int len = values.size();
        vector<int> memo(len, 0);
        memo[len - 1] = values[len - 1] - (len - 1);
        for (int i = len - 2; i >= 0; i--)
            memo[i] = max(memo[i + 1], values[i] - i);
        int ans = 0;
        for (int i = 0; i < len - 1; i++)
            ans = max(ans, values[i] + i + memo[i + 1]);
        return ans;
    }
};
#endif // ___Best_Sightseeing_Pair_1014_h___