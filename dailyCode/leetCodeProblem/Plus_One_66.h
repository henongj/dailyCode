
//https://leetcode.com/problems/plus-one/?envType=study-plan&id=programming-skills-ii
//66. Plus One
#ifndef ___Plus_One_66_h___
#define ___Plus_One_66_h___
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
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
		for (int i = digits.size() - 1; i >= 0; i--) {
			int sum = digits[i] + carry;
			digits[i] = sum % 10;
			carry = sum / 10;
		}
		if (carry == 1) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};


#endif // ___Plus_One_66_h___