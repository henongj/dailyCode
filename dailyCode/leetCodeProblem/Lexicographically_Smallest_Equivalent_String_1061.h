
#ifndef ___Lexicographically_Smallest_Equivalent_String_1061_h___
#define ___Lexicographically_Smallest_Equivalent_String_1061_h___
//https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
//1061. Lexicographically Smallest Equivalent String
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
using namespace std;

class Solution {
public:
	char alphabet[26] = {};
	char find(char c) {
		if (alphabet[c] == 0)
			return c;
		return alphabet[c] = find(alphabet[c]);
	}
	void unionSet(char a, char b)
	{
		char pa = find(a);
		char pb = find(b);
		if (pa != pb)
			alphabet[min(pa, pb)] = min(pa, pb);
	};
	string smallestEquivalentString(string s1, string s2, string baseStr) {
		for (int i = 0; i < s1.size(); i++)
			unionSet(s1[i] - 'a', s2[i] - 'a');
		for (int i = 0; i < baseStr.size(); i++)
			baseStr[i] = find(baseStr[i] - 'a') + 'a';
		return baseStr;
	}
};
#endif // ___Lexicographically_Smallest_Equivalent_String_1061_h___