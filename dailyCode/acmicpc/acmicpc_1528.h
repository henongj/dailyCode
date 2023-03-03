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


bool generateGeumMinSu(vector<int>* vGeumMinSu, int nLimitValueOfGeumMinSu);
void getSequenceSumOfGeumMinSu(vector<int>* vSequenceSumOfGeumMinSu, const vector<int>* vGeumMinSuTable, int nTarget);

int mainSpace(void)
{
	vector<int> vSequenceSumOfGeumMinSu{};
	vector<int> vGeumMinSuTable{};
	bool isError{};
	vGeumMinSuTable.reserve(1022);
	vSequenceSumOfGeumMinSu.reserve(10);
	int nTarget{};
	size_t szSequenceSumOfGeumMinSuSize{};

	cin >> nTarget;

	vGeumMinSuTable = { 4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777, 44444, 44447, 44474, 44477, 44744, 44747, 44774, 44777, 47444, 47447, 47474, 47477, 47744, 47747, 47774, 47777, 74444, 74447, 74474, 74477, 74744, 74747, 74774, 74777, 77444, 77447, 77474, 77477, 77744, 77747, 77774, 77777, 444444, 444447, 444474, 444477, 444744, 444747, 444774, 444777, 447444, 447447, 447474, 447477, 447744, 447747, 447774, 447777, 474444, 474447, 474474, 474477, 474744, 474747, 474774, 474777, 477444, 477447, 477474, 477477, 477744, 477747, 477774, 477777, 744444, 744447, 744474, 744477, 744744, 744747, 744774, 744777, 747444, 747447, 747474, 747477, 747744, 747747, 747774, 747777, 774444, 774447, 774474, 774477, 774744, 774747, 774774, 774777, 777444, 777447, 777474, 777477, 777744, 777747, 777774, 777777 };

	getSequenceSumOfGeumMinSu(&vSequenceSumOfGeumMinSu, &vGeumMinSuTable, nTarget);

	szSequenceSumOfGeumMinSuSize = vSequenceSumOfGeumMinSu.size();

	if (szSequenceSumOfGeumMinSuSize == 0)
		printf("-1");
	else
	{
		for (size_t i = 0; i < szSequenceSumOfGeumMinSuSize; i++)
			printf("%d ", vSequenceSumOfGeumMinSu[i]);
	}

	return 0;
}


bool generateGeumMinSu(vector<int>* vGeumMinSu, int nLimitValueOfGeumMinSu)
{
	if (nLimitValueOfGeumMinSu < 4)
		return false;

	queue<int> qGeumMinSu{};
	int nGeumMinSu{};
	int nDataToInput{};
	int nFour{};
	int nSeven{};
	int count{};
	size_t nQueueSize{};

	vGeumMinSu->reserve(1025);

	nFour = 4;
	nSeven = 7;

	qGeumMinSu.push(nFour);
	vGeumMinSu->push_back(nFour);
	qGeumMinSu.push(nSeven);
	vGeumMinSu->push_back(nSeven);
	count = 7;

	while (count * 2 <= nLimitValueOfGeumMinSu)
	{
		nQueueSize = (qGeumMinSu.size());

		for (int i = 0; i < nQueueSize; i++)
		{
			nGeumMinSu = qGeumMinSu.front();
			qGeumMinSu.pop();

			nDataToInput = (nGeumMinSu * 10) + nFour;
			vGeumMinSu->push_back(nDataToInput);
			qGeumMinSu.push(nDataToInput);

			nDataToInput = (nGeumMinSu * 10) + nSeven;
			vGeumMinSu->push_back(nDataToInput);
			qGeumMinSu.push(nDataToInput);
		}
		count = (count * 10) + 7;
	}

	return true;
}

void getSequenceSumOfGeumMinSu(vector<int>* vSequenceSumOfGeumMinSu, const vector<int>* vGeumMinSuTable, int nTarget)
{
	size_t szGeumMinSuTableSize{};
	size_t idx{};
	queue<vector<int>> qGeumMinSu{};

	szGeumMinSuTableSize = vGeumMinSuTable->size();
	idx = 0;
	while (idx < szGeumMinSuTableSize && (*vGeumMinSuTable)[idx] <= nTarget)
	{
		vector<int> vGeumMinSu{};

		vGeumMinSu.reserve(10);
		// vGeumMinSu[0] 합 , [1] 부터 수열 첫 번째
		vGeumMinSu.push_back((*vGeumMinSuTable)[idx]);
		vGeumMinSu.push_back((*vGeumMinSuTable)[idx]);

		qGeumMinSu.push(vGeumMinSu);

		idx++;
	}

	// 무차별 탐색
	while (!qGeumMinSu.empty())
	{
		int nSum{};
		int nTempTarget{};
		vector<int>* qFront{};
		qFront = &(qGeumMinSu.front());
		nSum = (*qFront)[0];

		idx = 0;
		while (idx < szGeumMinSuTableSize)
		{
			nTempTarget = nSum + (*vGeumMinSuTable)[idx];
			if (nTempTarget <= nTarget)
			{
				vector<int> vCopyVector{};
				vCopyVector.reserve(10);
				vCopyVector = (*qFront);

				vCopyVector.push_back((*vGeumMinSuTable)[idx]);

				// 답인 경우
				if (nTempTarget == nTarget)
				{
					vCopyVector[0] = nTempTarget;
					*vSequenceSumOfGeumMinSu = vCopyVector;
					return;
				}
				else if (nTempTarget < nTarget)
				{
					vCopyVector[0] = nTempTarget;
					qGeumMinSu.push(vCopyVector);
				}
			}

			idx++;
		}

		qGeumMinSu.pop();
	}

}
