#pragma once
#ifndef ___Find_Peak_Element_162_h___
#define ___Find_Peak_Element_162_h___
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

// code 2022_10_23
// https://leetcode.com/problems/find-peak-element/


class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;


        if (nums.size() == 1) return 0; // 원소가 하나
        if (nums[0] > nums[1]) return 0; // 가장 왼쪽이 peak
        if (nums[nums.size() - 2] < nums[nums.size() - 1]) return nums.size() - 1; // 가장 오른족이 peak


        while (left <= right) {
            middle = (right - left) / 2 + left; // 1 2 3 4 5
            std::cout << "(left, middle, right) : ( " << left << ", " << middle << ", " << right << " )\n";
            std::cout << "(middle-1, middle, middle+1) : ( " << nums[middle - 1] << ", " << nums[middle] << ", " << nums[middle + 1] << " )\n";
            //peak element 인 경우

            if (nums[middle - 1] < nums[middle] && nums[middle + 1] < nums[middle])
            {
                return middle;
            }
            // 증가 중인 경우
            else if (nums[middle] < nums[middle + 1])
            {
                left = middle + 1;
            }
            // 감소 중인 경우
            else if (nums[middle] < nums[middle - 1])
            {
                right = middle;
            }
        }

        return left;
    }
	
    public:
        int findPeakElement2(std::vector<int>& nums) {
            int lo = 0;
            int hi = nums.size() - 1;
            int mid = 0;

            while (lo < hi) {
                mid = lo + (hi - lo) / 2;
                if (nums[mid] < nums[mid + 1])
                    lo = mid + 1;
                else {
                    if (mid >= 1 && nums[mid] < nums[mid - 1])
                        hi = mid - 1;
                    else
                        return mid;
                }
            }

            return lo;
        }

};
#endif
