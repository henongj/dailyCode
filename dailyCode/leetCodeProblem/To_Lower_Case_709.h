
//https://leetcode.com/problems/to-lower-case/?envType=study-plan&id=programming-skills-i
//709. To Lower Case

#ifndef ___To_Lower_Case_709_h___
#define ___To_Lower_Case_709_h___
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
using namespace std;
class Solution {
public:
	string toLowerCase(string s) {
		string result = s;

		for (int idx = 0; idx < result.size(); idx++)
			((result[idx] >= 'A') && (result[idx] <= 'Z')) ? result[idx] = result[idx] + ' ' : result[idx];

		return result;
	}
};

/*
"Hello"
"here"
"LOVELY"
"al&phaBET"
*/
#endif // ___To_Lower_Case_709_h___