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
#include <fstream>
#include<functional>

//https://www.acmicpc.net/problem/15829
//Hashing
namespace acmicpc_15829
{

	void solution_acmicpc15829(void);
	int mainSpace_acmicpc15829(void)
	{
		//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

		solution_acmicpc15829();

		return 0;
	}

	void solution_acmicpc15829(void)
	{
		using namespace std;

		int nLength{};
		string strInput{};
		long long nResult{};
		long long nPow{ 1 };
		long long nMod{ 1234567891 };
		long long nR{ 31 };

		cin >> nLength;
		cin >> strInput;

		for (int i = 0; i < nLength; ++i)
		{
			nResult += (strInput[i] - 'a' + 1) * nPow;
			nPow *= nR;
			nPow %= nMod;
			nResult %= nMod;
		}

		cout << nResult << "\n";

	}
}
