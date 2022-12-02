
//https://leetcode.com/problems/n-th-tribonacci-number/?envType=study-plan&id=dynamic-programming-i
//1137. N-th Tribonacci Number
#ifndef ___N-th_Tribonacci_Number_1137_h___
#define ___N-th_Tribonacci_Number_1137_h___
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
    int tribonacci(int n) {
        vector<int> memo(50, -1);
        memo[0] = 0; memo[1] = 1; memo[2] = 1;

        if (n < 3)
            return memo[n];

        int idx = 3;
        for (; idx <= n; idx++)
            memo[idx] = memo[idx - 3] + memo[idx - 2] + memo[idx - 1];

        return memo[n];
    }
};


#endif // ___N-th_Tribonacci_Number_1137_h___

