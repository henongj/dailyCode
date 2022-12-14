
//https://leetcode.com/problems/repeated-substring-pattern/?envType=study-plan&id=programming-skills-ii
//459. Repeated Substring Pattern
#ifndef ___Repeated_Substring_Pattern_459_h___
#define ___Repeated_Substring_Pattern_459_h___
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
	bool repeatedSubstringPattern(string s) {
		int n = s.size();
		for (int i = 1; i <= n / 2; i++)
		{
			if (n % i == 0)
			{
				string sub = s.substr(0, i);
				int j = i;
				while (j < n)
				{
					if (s.substr(j, i) != sub)
						break;
					j += i;
				}
				if (j == n)
					return true;
			}
		}
		return false;
	}
};

#endif // ___Repeated_Substring_Pattern_459_h___

