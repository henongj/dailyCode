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
#include <fstream>
#include<functional>

namespace acmicpc_27866
{

	//https://www.acmicpc.net/problem/27866
	//문자와 문자열
	void solution_acmicpc27866(void);
	int mainSpace_acmicpc27866(void)
	{
		//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

		solution_acmicpc27866();

		return 0;
	}

	void solution_acmicpc27866(void)
	{
		using namespace std;

		int nIndex{};
		string strInput{};

		cin >> strInput;
		cin >> nIndex;

		char cResult = strInput[nIndex - 1];

		cout << cResult << "\n";

	}
}
