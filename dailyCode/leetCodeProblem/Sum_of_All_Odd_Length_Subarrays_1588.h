//https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
//1588. Sum of All Odd Length Subarrays
#ifndef ___Sum_of_All_Odd_Length_Subarrays_1588_h___
#define ___Sum_of_All_Odd_Length_Subarrays_1588_h___

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0, n = arr.size(), i;
        for (i = 0; i < n; i++)
        {
            int contribution = ceil((i + 1) * (n - i) / 2.0);
            ans += (contribution * arr[i]);
        }
        return ans;
    }
};
#endif // !___Sum_of_All_Odd_Length_Subarrays_1588_h___