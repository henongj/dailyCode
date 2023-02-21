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
#include<unordered_set>
#include<numeric>
using namespace std;


//https://leetcode.com/problems/single-element-in-a-sorted-array/
//540. Single Element in a Sorted Array
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int, int> mNumberCounter{};
        int vNumsSize{};
        int nAnswer{};
        vNumsSize = nums.size();

        nAnswer = 0;
        for (int i = 0; i < vNumsSize; i++)
        {
            if (mNumberCounter.count(nums[i]) == 0)
            {
                mNumberCounter[nums[i]] = nums[i];
                nAnswer += nums[i];
            }
            else
                nAnswer -= nums[i];
        }

        return nAnswer;
    }
};
