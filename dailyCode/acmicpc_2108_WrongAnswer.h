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

namespace acmicpc_2108_WrongAnswer
{
	//https://www.acmicpc.net/problem/2108
	//≈Î∞Ë«–
	void solution_acmicpc2108(void);


	void solution_acmicpc2108(void)
	{
		using namespace std;

		int nNumber{};
		vector<int> vNumber{};
		int nSum{};
		int nMaxCount{ 0 };
		int nMaxNumber{ 0 };
		bool bSecond{ false };

		cin >> nNumber;
		vNumber.reserve(nNumber);

		for (int i = 0; i < nNumber; ++i)
		{
			int nTemp{};
			cin >> nTemp;
			vNumber.push_back(nTemp);
			nSum += nTemp;
		}

		sort(vNumber.begin(), vNumber.end());

		cout << round((double)nSum / nNumber) << endl;
		cout << vNumber[nNumber / 2] << endl;

		map<int, int> mNumber{};

		for (int i = 0; i < nNumber; ++i)
		{
			if (mNumber.find(vNumber[i]) == mNumber.end())
				mNumber.insert(make_pair(vNumber[i], 1));
			else
				mNumber[vNumber[i]]++;
		}

		for (auto iter = mNumber.begin(); iter != mNumber.end(); ++iter)
		{
			if (nMaxCount < iter->second)
			{
				nMaxCount = iter->second;
				nMaxNumber = iter->first;
				bSecond = false;
			}
			else if (nMaxCount == iter->second && bSecond == false)
			{
				nMaxNumber = iter->first;
				bSecond = true;
			}
		}

		cout << nMaxNumber << endl;
		cout << vNumber[nNumber - 1] - vNumber[0] << endl;


	}

}