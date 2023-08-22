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
//https://www.acmicpc.net/problem/19598
//최소 회의실 개수
namespace acmicpc_19598_WrongAnswer
{
	using namespace std;

	void solution(void);
	void inputData(int& nSize, vector<pair<int, int>>& vMeeting);
	void solution(void)
	{
		int nSize{};
		vector<pair<int, int>> vMeeting{};
		int* arrRoom = new int[100005] {};
		int nMax = 0;
		inputData(nSize, vMeeting);

		for (int i = 0; i < nSize; ++i)
		{
			pair<int, int>& pMeeting = vMeeting[i];
			for (int j = pMeeting.first; j < pMeeting.second; j++)
			{
				arrRoom[j]++;
				nMax = max(nMax, arrRoom[j]);
			}
		}
		cout << nMax << endl;

		delete[] arrRoom;
	}

	void inputData(int& nSize, vector<pair<int, int>>& vMeeting)
	{
		cin >> nSize;
		vMeeting.resize(nSize);

		for (int i = 0; i < nSize; ++i)
			cin >> vMeeting[i].first >> vMeeting[i].second;
	}
}
