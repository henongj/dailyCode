#ifndef ___koko_eating_bananas_875_h___
#define ___koko_eating_bananas_875_h___
#include<vector>
class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int left = 1;
        int right = 1000000000;

        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (canEatInTime(piles, mid, h))
            {
                //cout << "mid : " << mid << "\n";
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return left;
    }

    bool canEatInTime(std::vector<int>& piles, int k, int h) {
        unsigned long long hour = 0;
        for (auto pile : piles) {
            hour = hour + (pile / k);
            if (pile % k != 0) hour++;
        }
        return hour <= h ? true : false;
    }
};
#endif