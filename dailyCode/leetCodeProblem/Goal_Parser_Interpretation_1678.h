
//https://leetcode.com/problems/goal-parser-interpretation/?envType=study-plan&id=programming-skills-i
//1678. Goal Parser Interpretation
#ifndef ___Goal_Parser_Interpretation_1678_h___
#define ___Goal_Parser_Interpretation_1678_h___
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
	string interpret(string command) {
		string result = "";
		result.reserve(command.length());

		string G = "G";
		string O = "()";
		string AL = "(al)";

		int idx = 0;
		while (idx < command.length()) {
			if (command[idx] == 'G') {
				result += G;
				idx++;
			}
			else if (command[idx] == '(')
			{
				if (command[idx + 1] == O[1]) {
					result += "o";
					idx += 2;
				}
				else if (command[idx + 1] == AL[1]) {
					result += "al";
					idx += 4;
				}
			}
		}
		return result;
	}
};
#endif // ___Goal_Parser_Interpretation_1678_h___
