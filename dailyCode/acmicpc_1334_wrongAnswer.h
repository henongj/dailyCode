#pragma once
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
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

//https://www.acmicpc.net/problem/1334
//다음 팰린드롬 수
std::string findNextPalindrome_acmicpc1334(const std::string& N) {
	// 자릿수 계산
	int length = N.length();
	std::string result;

	int middle = length / 2;

	std::string prefix = N.substr(0, middle);
	result = prefix + N[middle] + std::string(prefix.rbegin(), prefix.rend());

	if (result <= N)
	{
		int carry = 1;
		for (int i = middle - 1; i >= 0; i--)
		{
			int digit = prefix[i] - '0' + carry;
			carry = digit / 10;
			prefix[i] = '0' + (digit % 10);
		}
		if (length & 1)
			result = prefix + prefix[middle - 1] + std::string(prefix.rbegin(), prefix.rend());
		else
			result = prefix + std::string(prefix.rbegin(), prefix.rend());
	}

	return result;
}

void solution01_acmicpc1334(void)
{
	//const std::string end = "9125464735781725445009";
	std::string strInput{};

	while (strInput != "0")
	{
		std::cin >> strInput;

		std::string s = findNextPalindrome_acmicpc1334(strInput);

		std::cout << s << "\n";
	}


	return;
}

int mainSpace01_acmicpc1334(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	solution01_acmicpc1334();

	return 0;
}
