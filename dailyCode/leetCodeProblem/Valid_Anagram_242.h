
//https://leetcode.com/problems/valid-anagram/?envType=study-plan&id=programming-skills-i
// 242. Valid Anagram
#ifndef ___Valid_Anagram_242_h___
#define ___Valid_Anagram_242_h___
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
using namespace std;
class Solution {
public:
	bool isAnagram(string s, string t) {
		const int alphabet_size = 'Z' - 'A' + 1;

		int s_map[alphabet_size] = { 0 };
		int t_map[alphabet_size] = { 0 };

		for (int i = 0; i < s.size(); i++) {
			s_map[s[i] - 'a']++;
		}
		for (int i = 0; i < t.size(); i++) {
			t_map[t[i] - 'a']++;
		}


		for (int i = 0; i < alphabet_size; i++) {
			if (s_map[i] != t_map[i])
				return false;
		}

		return true;
	}
};


#endif // ___Valid_Anagram_242_h___

