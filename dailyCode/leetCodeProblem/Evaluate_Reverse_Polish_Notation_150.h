
//https://leetcode.com/problems/evaluate-reverse-polish-notation/?envType=study-plan&id=programming-skills-ii
//150. Evaluate Reverse Polish Notation

#ifndef ___Evaluate_Reverse_Polish_Notation_150_h___
#define ___Evaluate_Reverse_Polish_Notation_150_h___
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
	int evalRPN(vector<string>& tokens) {
		stack<long long> s;
		for (auto& t : tokens)
			if (t == "+" || t == "-" || t == "*" || t == "/") {
				long long op1 = s.top(); s.pop();
				long long op2 = s.top(); s.pop();
				if (t == "+") op1 = op2 + op1;
				if (t == "-") op1 = op2 - op1;
				if (t == "/") op1 = op2 / op1;
				if (t == "*") op1 = op2 * op1;
				s.push(op1);
			}
			else s.push(stoi(t));    // stoi - converts from string to int     
		return s.top();
	}
};

#endif // ___Evaluate_Reverse_Polish_Notation_150_h___