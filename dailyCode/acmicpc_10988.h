#pragma once
//https://www.acmicpc.net/problem/10988
//팰린드롬인지 확인하기
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

bool isPalindrome(const std::string& str);
void solution_acmic10988(void);


int mainSpace_acmicpc10988(void)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	solution_acmic10988();

	return 0;
}


bool isPalindrome(const std::string& str)
{
	int nIndexStart{};
	int nIndexEnd{};

	nIndexStart = 0;
	nIndexEnd = str.size() - 1;

	while (nIndexStart < nIndexEnd)
	{
		if (str[nIndexStart] != str[nIndexEnd])
			return false;

		nIndexStart++;
		nIndexEnd--;
	}

	return true;
}

void solution_acmic10988(void)
{
	std::string strText{};
	strText.reserve(100);
	std::cin >> strText;

	std::cout << isPalindrome(strText) << std::endl;
}
