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

//https://www.acmicpc.net/problem/2108
//≈Î∞Ë«–
namespace acmicpc_2108_WrongAnswer
{
	using namespace std;

	void solution(void);
	void inputData(int& nSize, vector<int>& vData);
	void solution(void)
	{
		int nSize{};
		vector<int> vData{};

		int nSum{};
		int nMax{};
		int nMin{};
		int nMid{};
		int nMode{};
		int nRange{};
		int nCount{};
		int nMaxCount{};


		inputData(nSize, vData);

		sort(vData.begin(), vData.end());

		nMax = vData.back();
		nMin = vData.front();

		for (int i = 0; i < nSize; ++i)
			nSum += vData[i];

		nMid = vData[nSize / 2];

		map<int, int> mMode{};
		for (int i = 0; i < nSize; ++i)
		{
			auto iter = mMode.find(vData[i]);
			if (iter == mMode.end())
				mMode.insert(iter, { vData[i], 1 });
			else
				++iter->second;
		}

		for (auto iter = mMode.begin(); iter != mMode.end(); ++iter)
		{
			if (nMaxCount < iter->second)
			{
				nMaxCount = iter->second;
				nMode = iter->first;
				nCount = 1;
			}
			else if (nMaxCount == iter->second)
			{
				if (nCount == 1)
				{
					nMode = iter->first;
					++nCount;
				}
			}
		}

		nRange = nMax - nMin;

		nSum = round((double)nSum / nSize);

		cout << nSum << endl;
		cout << nMid << endl;
		cout << nMode << endl;
		cout << nRange << endl;

	}
	void inputData(int& nSize, vector<int>& vData)
	{
		cin >> nSize;
		vData.resize(nSize);

		for (int i = 0; i < nSize; ++i)
			cin >> vData[i];
	}
}
