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
//https://www.acmicpc.net/problem/18870
//ÁÂÇ¥ ¾ÐÃà
namespace acmicpc_18870
{
	using namespace std;

	void solution(void);
	void inputData(int& nSize, vector<int>& vData);

	void solution(void)
	{

		int nSize{};
		vector<int> vData{};

		inputData(nSize, vData);

		vector<int> vSortData{ vData };
		sort(vSortData.begin(), vSortData.end());
		vSortData.erase(unique(vSortData.begin(), vSortData.end()), vSortData.end());

		for (int i = 0; i < nSize; i++)
		{
			cout << lower_bound(vSortData.begin(), vSortData.end(), vData[i]) - vSortData.begin() << " ";
		}



	}
	void inputData(int& nSize, vector<int>& vData)
	{
		cin >> nSize;
		vData.resize(nSize);
		for (int i = 0; i < nSize; i++)
			cin >> vData[i];
	}
}

