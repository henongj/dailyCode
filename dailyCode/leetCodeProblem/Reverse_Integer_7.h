//https://leetcode.com/problems/reverse-integer/
// 7. Reverse Integer
#ifndef ___Reverse_Integer_7_h__
#define ___Reverse_Integer_7_h__
class Solution {
public:
	int reverse(int x) {
		long long result = 0;
		while (x != 0) {
			result = result * 10 + x % 10;
			x /= 10;
		}
		return (result < INT_MIN || result > INT_MAX) ? -1 : result;
	}
};
#endif