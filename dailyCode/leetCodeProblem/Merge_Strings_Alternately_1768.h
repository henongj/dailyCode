
//https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan&id=programming-skills-i
//1768. Merge Strings Alternately
#ifndef ___Merge_Strings_Alternately_1768_h___
#define ___Merge_Strings_Alternately_1768_h___
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
	string mergeAlternately(string word1, string word2) {
		string result;

		int idx1 = 0;
		int idx2 = 0;

		while (1) {
			if (idx1 < word1.length())
				result.push_back(word1[idx1++]);
			if (idx2 < word2.length())
				result.push_back(word2[idx2++]);

			if (idx1 >= word1.length() && idx2 >= word2.length())
				break;
		}

		return result;
	}
};

#endif // ___Merge_Strings_Alternately_1768_h___
