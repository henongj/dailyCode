
// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
//1790. Check if One String Swap Can Make Strings Equal
#ifndef ___Check_if_One_String_Swap_Can_Make_Strings_Equal_1790_h___
#define ___Check_if_One_String_Swap_Can_Make_Strings_Equal_1790_h___

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
	bool areAlmostEqual(string s1, string s2) {
		int cnt = 0;
		int idx1 = -1;
		int idx2 = -1;
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] != s2[i])
			{
				cnt++;
				if (cnt > 2)
				{
					return false;
				}
				if (idx1 == -1)
				{
					idx1 = i;
				}
				else
				{
					idx2 = i;
				}
			}
		}
		if (cnt == 0)
		{
			return true;
		}
		if (cnt == 2)
		{
			if (s1[idx1] == s2[idx2] && s1[idx2] == s2[idx1])
			{
				return true;
			}
		}
		return false;
	}
};

#endif // ___Check_if_One_String_Swap_Can_Make_Strings_Equal_1790_h___
