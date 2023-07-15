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
bool isAllNine_acmicpc1334(const std::string& str);
void compareStringAsNumber_acmicpc1334(const std::string& str1, const std::string& str2, std::string*& pResult);
void makePalindromeByHalf_acmicpc1334(const std::string& strHalf, std::string& strResult);
void carry_acmicpc1334(std::string& str1, int nIndex);
void solution_acmicpc1334(void);

int mainSpace01_acmicpc1334(void)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	solution_acmicpc1334();

	return 0;
}

void solution_acmicpc1334(void)
{
	std::string strInput{};

	std::cin >> strInput;
	int nStrLength{};

	nStrLength = strInput.size();
	std::string strHalf{};
	strHalf = strInput.substr(0, nStrLength / 2);
	std::string strNextPalindrome{};
	strNextPalindrome.reserve(50);
	char cOverNine = '9' + 1;

	if (nStrLength == 1)
	{
		if (strInput[0] == '9')
			std::cout << "11";
		else
			std::cout << ++strInput[0];
		return;
	}
	else if (isAllNine_acmicpc1334(strInput))
	{
		//5자리면 앞뒤가 1이고 나머지가 0인 5+1자리 문자열을 출력해야
		for (int i = 0; i < nStrLength; i++)
			strNextPalindrome.push_back('0');
		strNextPalindrome[0] = '1';
		strNextPalindrome.push_back('1');
		std::cout << strNextPalindrome;
	}
	else
	{
		int nMiddle = nStrLength / 2;
		std::string* pStrBigger{};

		makePalindromeByHalf_acmicpc1334(strHalf, strNextPalindrome);
		if (nStrLength & 1)
			strNextPalindrome.insert(nMiddle, 1, strInput[nMiddle]);

		compareStringAsNumber_acmicpc1334(strNextPalindrome, strInput, pStrBigger);
		if (pStrBigger == &strInput || pStrBigger == nullptr) //pStrBigger == nullptr 이면 그 수는 펠린드롬 수
		{
			if (!(nStrLength & 1))
				nMiddle--;
			strNextPalindrome[nMiddle] = strNextPalindrome[nMiddle] + 1;

			char c = strNextPalindrome[nMiddle];
			if (c == cOverNine)
				c = '0';

			carry_acmicpc1334(strNextPalindrome, nMiddle);
			makePalindromeByHalf_acmicpc1334(strNextPalindrome.substr(0, nStrLength / 2), strNextPalindrome);
			if (nStrLength & 1)
				strNextPalindrome.insert(nMiddle, 1, c);
		}

		std::cout << strNextPalindrome;
	}

	return;
}

bool isAllNine_acmicpc1334(const std::string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != '9')
			return false;
	}
	return true;
}
void compareStringAsNumber_acmicpc1334(const std::string& str1, const std::string& str2, std::string*& pResult)
{
	int nLengthStr1{};
	int nLengthStr2{};

	nLengthStr1 = str1.size();
	nLengthStr2 = str2.size();

	if (nLengthStr1 < nLengthStr2)
	{
		pResult = const_cast<std::string*>(&str2);
		return;
	}

	if (nLengthStr1 > nLengthStr2)
	{
		pResult = const_cast<std::string*>(&str1);
		return;
	}

	for (int i = 0; i < nLengthStr1; i++)
	{
		if (str1[i] > str2[i])
		{
			pResult = const_cast<std::string*>(&str1);
			return;
		}
		else if (str1[i] < str2[i])
		{
			pResult = const_cast<std::string*>(&str2);
			return;
		}
	}
}

void makePalindromeByHalf_acmicpc1334(const std::string& strHalf, std::string& strResult)
{
	strResult = strHalf;
	for (int i = strHalf.size() - 1; i >= 0; i--)
		strResult.push_back(strHalf[i]);
}

void carry_acmicpc1334(std::string& str1, int nIndex)
{
	char compare = '9' + 1;
	for (int i = nIndex; i > 0; i--)
	{
		if (str1[i] == compare)
		{
			str1[i] = '0';
			str1[i - 1] = str1[i - 1] + 1;
		}
	}
}
