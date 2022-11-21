
//https://leetcode.com/problems/roman-to-integer/
// 13. Roman to Integer
#ifndef ___Roman_to_Integer_13_h___
#define ___Roman_to_Integer_13_h___
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

	int romanToInt(string s) {
		// i = 1 v = 5 x = 10 l = 50 c = 100 d = 500 m = 1000
		unordered_map <char, int> romanMap;
		romanMap['I'] = 1;
		romanMap['V'] = 5;
		romanMap['X'] = 10;
		romanMap['L'] = 50;
		romanMap['C'] = 100;
		romanMap['D'] = 500;
		romanMap['M'] = 1000;

		int result = 0;
		char before_character = ' ';
		for (int idx = 0; idx < s.size(); idx++) {

			if (idx != 0)
				before_character = s[idx - 1];


			// 이전 글자 [I -> V, X] [X -> L, C] [C -> D, M]
			if (((s[idx] == 'V' || s[idx] == 'X') && before_character == 'I') ||
				((s[idx] == 'C' || s[idx] == 'L') && before_character == 'X') ||
				((s[idx] == 'D' || s[idx] == 'M') && before_character == 'C'))
				result = result + romanMap[s[idx]] - romanMap[before_character] * 2;
			else
				result = result + romanMap[s[idx]];
		}
		return result;
	}
};


#endif