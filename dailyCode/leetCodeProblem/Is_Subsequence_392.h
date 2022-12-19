
//https://leetcode.com/problems/is-subsequence/description/?envType=study-plan&id=dynamic-programming-i
//392. Is Subsequence
#ifndef ___Is_Subsequence_392_h___
#define ___Is_Subsequence_392_h___
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
	bool isSubsequence(string s, string t) {
		unordered_map<char, vector<int>> m;
		for (int i = 0; i < t.size(); ++i) {
			m[t[i]].push_back(i);
		}
		int prev = -1;
		for (int i = 0; i < s.size(); ++i) {
			auto it = m.find(s[i]);
			if (it == m.end())
				return false;

			auto it2 = upper_bound(it->second.begin(), it->second.end(), prev);
			if (it2 == it->second.end())
				return false;
			prev = *it2;
		}
		return true;
	}
};

#endif // ___Is_Subsequence_392_h___

