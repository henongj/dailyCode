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
using namespace std;

bool funcRotateVector(const vector<vector<int>>& vSource, vector<vector<int>>* pVec);

int mainTest(void)
{
	vector<vector<int>> vSource = { {1,2,3,4,5,6,7,8,9,10},
									{11,12,13,14,15,16,17,18,19,20},
									{21,22,23,24,25,26,27,28,29,30},
									{31,32,33,34,35,36,37,38,39,40},
									{41,42,43,44,45,46,47,48,49,50},
									{51,52,53,54,55,56,57,58,59,60},
									{61,62,63,64,65,66,67,68,69,70},
									{71,72,73,74,75,76,77,78,79,80},
									{81,82,83,84,85,86,87,88,89,90},
									{91,92,93,94,95,96,97,98,99,100} };

	funcRotateVector(vSource, &vSource);

	for (auto& v : vSource)
	{
		for (auto& n : v)
		{
			cout << n << " ";
		}
		cout << endl;
	}

	return 0;
}

bool funcRotateVector(const vector<vector<int>>& vSource, vector<vector<int>>* pVec)
{
	if (vSource.empty())
		return false;

	int nRowSize = (int)vSource.size();
	int nColSize = (int)vSource[0].size();
	pVec->resize(nRowSize);
	for (int i = 0; i < nRowSize; ++i)
	{
		(*pVec)[i].resize(nColSize);
	}

	for (int i = 0; i < nRowSize; ++i)
	{
		for (int j = 0; j < nColSize; ++j)
		{
			(*pVec)[i][j] = vSource[nRowSize - 1 - j][i];
		}
	}

	return true;
}