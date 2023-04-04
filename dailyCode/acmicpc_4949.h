#pragma once
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
#include<set>

//https://www.acmicpc.net/problem/4949
//±ÕÇüÀâÈù ¼¼»ó
void dataInput(std::vector<std::string>& vStr);
bool isBlanced(const std::string& str);
void acmicpc_4949(void)
{
	// input data include space
	std::vector<std::string> vStr{};
	std::string strSentence{};
	strSentence.reserve(100);
	while (true)
	{
		std::getline(std::cin, strSentence);
		if (strSentence.size() == 1 && strSentence[0] == '.')
			return;

		if (isBlanced(strSentence))
			std::cout << "yes\n";
		else
			std::cout << "no\n";
	}
}

void dataInput(std::vector<std::string>& vStr)
{
	std::string strSentence{};
	strSentence.reserve(100);
	while (true)
	{
		std::getline(std::cin, strSentence);
		if (strSentence == ".")
			break;
		vStr.push_back(strSentence);
	}
}

bool isBlanced(const std::string& str)
{
	std::stack<char> stkBracketOrder{};

	for (const auto& c : str)
	{
		if (c == '(' || c == '[')
			stkBracketOrder.push(c);
		else if (c == ')')
		{
			if (stkBracketOrder.empty() || stkBracketOrder.top() != '(')
				return false;
			stkBracketOrder.pop();
		}
		else if (c == ']')
		{
			if (stkBracketOrder.empty() || stkBracketOrder.top() != '[')
				return false;
			stkBracketOrder.pop();
		}
	}

	if (stkBracketOrder.empty())
		return true;
	else
		return false;
}
