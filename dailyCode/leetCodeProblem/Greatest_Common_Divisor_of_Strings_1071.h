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

//https://leetcode.com/problems/greatest-common-divisor-of-strings/
// 1071. Greatest_Common_Divisor_of_Strings_1071
class Solution {
public:
	string gcdOfStrings(string str1, string str2) {
		if (str1 + str2 != str2 + str1)
			return "";
		return str1.substr(0, gcd(str1.size(), str2.size()));
	}

};