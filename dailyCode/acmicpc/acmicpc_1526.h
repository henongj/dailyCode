#pragma once
//https://www.acmicpc.net/problem/1526
//가장 큰 금민수
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
#include<stack>
#include<cmath>
#include<set>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;

bool generateGeumMinSu(vector<string>* vGeumMinSu, int nLimitValueOfGeumMinSu);
void printGeumMinSuListToMakeTable(int nLimitValue);
bool getBiggestGeumMinSu(vector<int>* vGeumMinSuTable, int nLimitValue, int* nResult);

int mainSpace(void)
{
	vector<int> vGeumMinSuTable{};
	vGeumMinSuTable.reserve(1025);
	vGeumMinSuTable = { 4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777, 44444, 44447, 44474, 44477, 44744, 44747, 44774, 44777, 47444, 47447, 47474, 47477, 47744, 47747, 47774, 47777, 74444, 74447, 74474, 74477, 74744, 74747, 74774, 74777, 77444, 77447, 77474, 77477, 77744, 77747, 77774, 77777, 444444, 444447, 444474, 444477, 444744, 444747, 444774, 444777, 447444, 447447, 447474, 447477, 447744, 447747, 447774, 447777, 474444, 474447, 474474, 474477, 474744, 474747, 474774, 474777, 477444, 477447, 477474, 477477, 477744, 477747, 477774, 477777, 744444, 744447, 744474, 744477, 744744, 744747, 744774, 744777, 747444, 747447, 747474, 747477, 747744, 747747, 747774, 747777, 774444, 774447, 774474, 774477, 774744, 774747, 774774, 774777, 777444, 777447, 777474, 777477, 777744, 777747, 777774, 777777 };

	int nLimitRange{};
	int nMaximumGeumMinSu{};

	cin >> nLimitRange;
	getBiggestGeumMinSu(&vGeumMinSuTable, nLimitRange, &nMaximumGeumMinSu);

	cout << nMaximumGeumMinSu;

	return 0;
}



void printGeumMinSuListToMakeTable(int nLimitValue)
{
	vector<string> vGeumMinSu{};
	vGeumMinSu.reserve(1025);
	int nSize{};
	generateGeumMinSu(&vGeumMinSu, nLimitValue);

	nSize = vGeumMinSu.size();

	cout << "{ ";
	for (int i = 0; i < nSize - 1; i++)
		cout << vGeumMinSu[i] << ", ";

	cout << vGeumMinSu[nSize - 1] << " }";
}

bool getBiggestGeumMinSu(vector<int>* vGeumMinSuTable, int nLimitRange, int* nResult)
{
	if (nLimitRange < 4)
		return false;

	int nSize{};
	nSize = vGeumMinSuTable->size();

	for (int i = 0; i < nSize; i++)
	{
		if ((*vGeumMinSuTable)[i] <= nLimitRange)
			*nResult = (*vGeumMinSuTable)[i];
		else
			return true;
	}
	return true;
}

bool generateGeumMinSu(vector<string>* vGeumMinSu, int nLimitValueOfGeumMinSu)
{
	if (nLimitValueOfGeumMinSu < 4)
		return false;

	queue<string> qGeumMinSu{};
	string strGeumMinSu{};
	string strDataToInput{};
	string strLimitValueOfGeumMinSu{};
	string cFour{};
	string cSeven{};
	int count{};
	size_t nQueueSize{};

	vGeumMinSu->reserve(1025);

	cFour = "4";
	cSeven = "7";

	strLimitValueOfGeumMinSu = to_string(nLimitValueOfGeumMinSu);

	// 1. stackGMS에 strGMS 에 "4"를 붙인 것 또는 "7"을 붙인 것을 push
	// 2. nLimitNthGMS 만큼 반복

	qGeumMinSu.push("4");
	vGeumMinSu->push_back("4");
	qGeumMinSu.push("7");
	vGeumMinSu->push_back("7");
	count = 7;
	while (count * 2 <= nLimitValueOfGeumMinSu)
	{
		nQueueSize = (qGeumMinSu.size());

		for (int i = 0; i < nQueueSize; i++)
		{
			strGeumMinSu = qGeumMinSu.front();
			qGeumMinSu.pop();

			strDataToInput = strGeumMinSu + cFour;
			vGeumMinSu->push_back(strDataToInput);
			qGeumMinSu.push(strDataToInput);

			strDataToInput = strGeumMinSu + cSeven;
			vGeumMinSu->push_back(strDataToInput);
			qGeumMinSu.push(strDataToInput);
		}
		count = (count * 10) + 7;
	}

	return true;
}

