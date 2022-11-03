#ifndef ___Count_Odd_Numbers_in_an_Interval_Range_1523_h___
#define ___Count_Odd_Numbers_in_an_Interval_Range_1523_h___

//https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/


class Solution {
public:
    int countOdds(int low, int high) {
        int num = 0;
        for (low; low <= high; low++)
            low & 1 ? ++num : num;
        return num;
    }
};

#endif