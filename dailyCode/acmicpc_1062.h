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

//https://www.acmicpc.net/problem/1062
//°¡¸£Ä§
void solution_acmicpc1062(void);
int countCanReadWords_acmicpc1062(const std::vector<std::string>& vWords, const std::vector<bool>& canRead);
void teachAlphabet_acmicpc1062(const std::vector<std::string>& vWords, std::vector<bool>& vPicked, const int nIndex, const int nHowMandPick, const int nPicked, int& nResult);
void dataInput_acmicpc1062(int& nWords, int& nAlphabet, std::vector<std::string>& vWords);

int mainSpace01_acmicpc1062(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	solution_acmicpc1062();

	return 0;
}

void solution_acmicpc1062(void)
{
	int nWords{};
	int nAlphabet{};
	std::vector<std::string> vWords;
	int nResult{};

	dataInput_acmicpc1062(nWords, nAlphabet, vWords);

	nResult = 0;
	if (nAlphabet < 5)
	{
		std::cout << nResult;
		return;
	}
	else if (nAlphabet == 26)
	{
		std::cout << nWords;
		return;
	}

	std::vector<bool> vPicked{};
	vPicked.resize(256);
	vPicked['a'] = true;	vPicked['n'] = true;	vPicked['t'] = true;	vPicked['i'] = true;	vPicked['c'] = true;

	teachAlphabet_acmicpc1062(vWords, vPicked, 'a', nAlphabet - 5, 0, nResult);

	std::cout << nResult << "\n";
}

int countCanReadWords_acmicpc1062(const std::vector<std::string>& vWords, const std::vector<bool>& canRead)
{
	int nResult{};
	for (int i = 0; i < vWords.size(); ++i)
	{
		bool bCanRead{};
		bCanRead = true;

		for (int j = 0; j < vWords[i].size(); ++j)
		{
			if (canRead[vWords[i][j]] == false)
			{
				bCanRead = false;
				break;
			}
		}
		if (bCanRead)
			nResult++;
	}

	return nResult;
}

void teachAlphabet_acmicpc1062(const std::vector<std::string>& vWords, std::vector<bool>& vPicked, const int nIndex, const int nHowMandPick, const int nPicked, int& nResult)
{

	if (nHowMandPick == nPicked)
	{
		nResult = std::max(nResult, countCanReadWords_acmicpc1062(vWords, vPicked));
		return;
	}
	else //else if(nHowMandPick < nPicked)
	{
		for (int i = nIndex; i <= 'z'; i++)
		{
			while (vPicked[i] && i < 'z')
				i++;
			vPicked[i] = true;
			teachAlphabet_acmicpc1062(vWords, vPicked, i + 1, nHowMandPick, nPicked + 1, nResult);

			vPicked[i] = false;
		}
	}

}

void dataInput_acmicpc1062(int& nWords, int& nAlphabet, std::vector<std::string>& vWords)
{
	std::cin >> nWords;
	std::cin >> nAlphabet;
	vWords.resize(nWords);
	for (int i = 0; i < nWords; i++)
	{
		std::cin >> vWords[i];
	}

}
