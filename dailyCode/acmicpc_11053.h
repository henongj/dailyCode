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

//https://www.acmicpc.net/problem/11053
//가장 긴 증가하는 부분 수열
namespace acmicpc_11053 {
	using namespace std;

	void solution(void);
	void inputData(int& nLength, vector<int>& vNumbers);
	void solution(void)
	{
		int nLength{};
		vector<int> vNumbers;
		vector<pair<int, int>> vMemo{};

		inputData(nLength, vNumbers);
		vMemo.reserve(nLength);

		for (int i = 0; i < nLength; i++)
		{
			int nMax = 0;
			int nMaxIndex = 0;

			for (int j = 0; j < i; j++)
			{
				if (vNumbers[j] < vNumbers[i])
				{
					if (nMax < vMemo[j].second)
					{
						nMax = vMemo[j].second;
						nMaxIndex = j;
					}
				}
			}
			vMemo.push_back({ nMaxIndex, nMax + 1 });
		}

		int nMax = 0;
		int nMaxIndex = 0;

		for (int i = 0; i < nLength; i++)
		{
			if (nMax < vMemo[i].second)
			{
				nMax = vMemo[i].second;
				nMaxIndex = i;
			}
		}

		cout << nMax << endl;

	}

	void inputData(int& nLength, std::vector<int>& vNumbers)
	{
		cin >> nLength;
		vNumbers.resize(nLength);

		for (int i = 0; i < nLength; i++)
			cin >> vNumbers[i];
	}
}

int main(void)
{
	acmicpc_11053::solution();

	return 0;
}
