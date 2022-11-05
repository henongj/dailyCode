
#ifndef ___Number_of_1_Bits_191_h___
#define ___Number_of_1_Bits_191_h___
/*
	191. Number of 1 Bits
	https://leetcode.com/problems/number-of-1-bits/

*/
class Solution {
public:
	int hammingWeight(uint32_t n)
	{
		int count = 0;
		while (n != 0)
		{
			if ((n & 1) == 1)
			{
				count++;
			}
			n = n >> 1;
		}
		return count;
	}
};
#endif
