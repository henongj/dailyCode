//https://leetcode.com/problems/next-greater-element-i/?envType=study-plan&id=programming-skills-i
//496. Next Greater Element I
#ifndef ___Next_Greater_Element_I_496_h___
#define ___Next_Greater_Element_I_496_h___
#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		for (int idx1 = 0; idx1 < nums1.size(); idx1++) {
			int idx2 = 0;
			for (; idx2 < nums2.size(); idx2++) {
				if (nums1[idx1] == nums2[idx2]) {
					break;
				}
			}
			int idx3 = idx2 + 1;
			for (; idx3 < nums2.size(); idx3++) {
				if (nums2[idx3] > nums1[idx1]) {
					result.push_back(nums2[idx3]);
					break;
				}
			}
			if (idx3 == nums2.size()) {
				result.push_back(-1);
			}
		}

		return result;
	}
};


#endif // ___Next_Greater_Element_I_496_h___