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

//https://leetcode.com/problems/add-to-array-form-of-integer/description/
//989. Add to Array-Form of Integer
class Solution {
public:
	vector<int> addToArrayForm(vector<int>& num, int k) {
		vector<int> res;
		int carry = 0;
		int i = num.size() - 1;
		while (i >= 0 || k > 0 || carry > 0) {
			int sum = carry;
			if (i >= 0) {
				sum += num[i];
				i--;
			}
			if (k > 0) {
				sum += k % 10;
				k /= 10;
			}
			res.push_back(sum % 10);
			carry = sum / 10;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};