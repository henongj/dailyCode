
//https://leetcode.com/problems/find-the-difference/?envType=study-plan&id=programming-skills-i
//389. Find the Difference
#ifndef ___Find_the_Difference_389_h___
#define ___Find_the_Difference_389_h___
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
	char findTheDifference(string s, string t) {
		char result = ' ';

		int num_of_alphabet = 'z' - 'a' + 1;
		vector<int> s_alphabet(num_of_alphabet, 0);
		vector<int> t_alphabet(num_of_alphabet, 0);

		for (auto c : s)
			s_alphabet[c - 'a']++;
		for (auto c : t)
			t_alphabet[c - 'a']++;

		for (int i = 0; i < num_of_alphabet; i++) {
			if (s_alphabet[i] != t_alphabet[i]) {
				result = i + 'a';
				break;
			}
		}
		return result;
	}
};

#endif // ___Find_the_Difference_389_h___
