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

//https://www.acmicpc.net/problem/11055
//가장 큰 증가하는 부분 수열
namespace acmicpc_11055
{
	using namespace std;

	void solution(void);
	void inputData(int& nLength, vector<int>& vNumbers);

	void solution(void)
	{
		int nLength{};
		vector<int> vNumbers{};
		int nMax = 0;

		inputData(nLength, vNumbers);

		vector<int> vMemo(nLength, 0);
		vMemo[0] = vNumbers[0];

		for (int i = 1; i < nLength; i++)
		{
			int nMax = 0;

			for (int j = 0; j < i; j++)
			{
				if (vNumbers[j] < vNumbers[i])
				{
					if (nMax < vMemo[j])
						nMax = vMemo[j];
				}
			}
			vMemo[i] = nMax + vNumbers[i];
		}

		for (int i = 0; i < nLength; i++)
		{
			if (nMax < vMemo[i])
				nMax = vMemo[i];
		}

		cout << nMax << "\n";


	}
	void inputData(int& nLength, vector<int>& vNumbers)
	{
		cin >> nLength;
		vNumbers.resize(nLength);

		for (int i = 0; i < nLength; i++)
			cin >> vNumbers[i];

	}
}
