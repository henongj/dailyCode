#ifndef ___Running_Sum_of_1d_Array_1480_h___
#define ___Running_Sum_of_1d_Array_1480_h___

class Solution{
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        int sum = 0;
        for (auto i : nums)
        {
            sum += i;
            result.push_back(sum);
        }
        return result;
    }
};

#endif