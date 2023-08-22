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
namespace acmicpc_19598
{
	using namespace std;
	void solution(void);
	void inputData(int& nSize, vector<pair<int, int>>& vMeeting);

	void solution(void)
	{
		int nSize{};
		vector<pair<int, int>> vMeeting{};
		priority_queue<int, vector<int>, greater<int>> pqRoom;

		inputData(nSize, vMeeting);

		sort(vMeeting.begin(), vMeeting.end());

		pqRoom.push(vMeeting[0].second);

		for (int i = 1; i < nSize; ++i)
		{
			if (pqRoom.top() <= vMeeting[i].first)
				pqRoom.pop();

			pqRoom.push(vMeeting[i].second);
		}

		cout << pqRoom.size() << endl;
	}

	void inputData(int& nSize, vector<pair<int, int>>& vMeeting)
	{
		cin >> nSize;
		vMeeting.resize(nSize);

		for (int i = 0; i < nSize; ++i)
			cin >> vMeeting[i].first >> vMeeting[i].second;
	}
}
