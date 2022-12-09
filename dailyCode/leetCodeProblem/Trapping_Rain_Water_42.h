
//https://leetcode.com/problems/trapping-rain-water/description/
//42. Trapping Rain Water
#ifndef ___Trapping_Rain_Water_42_h___
#define ___Trapping_Rain_Water_42_h___
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

// dynamic programming solution
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        left[0] = height[0];
        right[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
            right[n - 1 - i] = max(right[n - i], height[n - 1 - i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            cout << left[i] << " " << right[i] << endl;

            res += min(left[i], right[i]) - height[i];
        }
        return res;
    }
    /*
    * testcase
    * height = [0,1,0,2,1,0,1,3,2,1,2,1]
    * left, right = (0 3) (1 3) (1 3) (2 3) (2 3) (2 3) (2 3) (3 3) (3 2) (3 2) (3 2) (3 1)
    * res = (min(0,3) - 0) ... = 6
    */
};

// two pointer solution
class Solution2 {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int left_index = left;
        int right_index = right;
        int water = 0;
        while (left != right)
        {
            if (height[left] <= height[right])
            {
                left_index++;

                if (height[left_index] < height[left])
                    water = water + (height[left] - height[left_index]);
                else
                    left = left_index;
            }
            else
            {
                right_index--;

                if (height[right_index] < height[right])
                    water = water + (height[right] - height[right_index]);
                else
                    right = right_index;
            }
        }

        return water;
    }
};


#endif // ___Trapping_Rain_Water_42_h___
