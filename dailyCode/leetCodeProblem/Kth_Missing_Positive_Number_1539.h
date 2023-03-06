
//https://leetcode.com/problems/kth-missing-positive-number/
//1539. Kth Missing Positive Number
class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		int nSize{};
		int nMissingCount{};
		int nMissingNumber{};

		nSize = arr.size();
		for (int nIndex = 0; nIndex < nSize; nIndex++)
		{
			nMissingCount = arr[nIndex] - nIndex - 1;

			if (nMissingCount >= k)
			{
				nMissingNumber = arr[nIndex] - k;
				break;
			}
			else
			{
				k -= nMissingCount;
			}
		}

		if (nMissingNumber == 0)
			nMissingNumber = arr[nSize - 1] + k;

		return nMissingNumber;
	}
};