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

namespace acmicpc_18110
{

	//https://www.acmicpc.net/problem/18110
	//solved.ac
	void solution_acmicpc18110(void);

	void solution_acmicpc18110(void)
	{
		using namespace std;
		int nNumSize{};
		vector<int> vNumber{};
		int nResult{};
		nResult = 0;

		cin >> nNumSize;
		vNumber.reserve(nNumSize);

		if (nNumSize == 0)
		{
			cout << nResult;
			return;
		}

		for (int i = 0; i < nNumSize; ++i)
		{
			int nTemp{};
			cin >> nTemp;
			vNumber.push_back(nTemp);
		}

		sort(vNumber.begin(), vNumber.end());

		int idx = round(nNumSize * 0.15);
		double nSum{};

		for (int i = idx; i < nNumSize - idx; i++)
			nSum += vNumber[i];

		nResult = round(nSum / (nNumSize - idx * 2));

		cout << nResult << "\n";

	}
}
