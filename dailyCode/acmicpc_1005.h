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

//https://www.acmicpc.net/problem/1005
//ACM Craft
namespace acmicpc1005
{
	void solution_acmicpc1005(void);
	void inputData_acmicpc1005(int& nBuildings, int& nOrders, int& nTargetBuilding, std::vector<int>& vBuildingTimes, std::vector<std::vector<int>>& vvBuildTree);
	bool canBuild(int nStart, const std::vector<bool>& vIsBuilt, const std::vector<std::vector<int>>& vvBuildTree);
	void build(int nStart, std::vector<bool>& vIsBuilt, const std::vector<std::vector<int>>& vvBuildTree, const std::vector<int>& vBuildingTimes, std::vector<int>& vBuildingTimesSum);
	int mainSpace_acmicpc1005(void)
	{
		solution_acmicpc1005();

		return 0;
	}

	void solution_acmicpc1005(void)
	{
		using namespace std;

		int nTestCase{};

		cin >> nTestCase;

		int nBuildings{};
		int nOrders{};
		int nTargetBuilding{};
		vector<int> vBuildingTimes{};
		vector<vector<int>> vvBuildTree{};
		vector<bool> vIsBuilt{};
		vector<int> vBuildingTimesSum{};
		for (int i = 0; i < nTestCase; i++)
		{
			vBuildingTimes.clear();
			vvBuildTree.clear();
			vIsBuilt.clear();
			vBuildingTimesSum.clear();

			inputData_acmicpc1005(nBuildings, nOrders, nTargetBuilding, vBuildingTimes, vvBuildTree);

			vIsBuilt.resize(nBuildings, false);
			vBuildingTimes.resize(nBuildings, 0);
			int nStart = nTargetBuilding - 1;

			vBuildingTimesSum.resize(nBuildings, 0);
			for (int i = 0; i < nBuildings; i++)
				vBuildingTimesSum[i] = vBuildingTimes[i];

			while (!canBuild(nStart, vIsBuilt, vvBuildTree))
			{
				for (int j = 0; j < vvBuildTree[nStart].size(); j++)
				{
					build(vvBuildTree[nStart][j], vIsBuilt, vvBuildTree, vBuildingTimes, vBuildingTimesSum);
				}
			}
			build(nStart, vIsBuilt, vvBuildTree, vBuildingTimes, vBuildingTimesSum);

			cout << vBuildingTimesSum[nStart] << "\n";

		}
	}

	void inputData_acmicpc1005(int& nBuildings, int& nOrders, int& nTargetBuilding, std::vector<int>& vBuildingTimes, std::vector<std::vector<int>>& vvBuildTree)
	{
		using namespace std;

		cin >> nBuildings;
		cin >> nOrders;

		vBuildingTimes.resize(nBuildings);
		vvBuildTree.resize(nBuildings);

		for (int i = 0; i < nBuildings; i++)
			cin >> vBuildingTimes[i];

		for (int i = 0; i < nOrders; i++)
		{
			vvBuildTree.reserve(10);
			int nFrom{};
			int nTo{};
			cin >> nFrom;
			cin >> nTo;

			vvBuildTree[nTo - 1].push_back(nFrom - 1);
		}

		cin >> nTargetBuilding;
	}

	bool canBuild(int nStart, const std::vector<bool>& vIsBuilt, const std::vector<std::vector<int>>& vvBuildTree)
	{
		using namespace std;

		if (vIsBuilt[nStart])
			return true;

		for (int i = 0; i < vvBuildTree[nStart].size(); i++)
		{
			if (!vIsBuilt[vvBuildTree[nStart][i]])
				return false;
		}

		return true;
	}

	void build(int nStart, std::vector<bool>& vIsBuilt, const std::vector<std::vector<int>>& vvBuildTree, const std::vector<int>& vBuildingTimes, std::vector<int>& vBuildingTimesSum)
	{
		using namespace std;
		int nSum{};

		if (vIsBuilt[nStart])
			return;

		for (int i = 0; i < vvBuildTree[nStart].size(); i++)
		{
			if (!vIsBuilt[vvBuildTree[nStart][i]])
				build(vvBuildTree[nStart][i], vIsBuilt, vvBuildTree, vBuildingTimes, vBuildingTimesSum);
		}
		for (int i = 0; i < vvBuildTree[nStart].size(); i++)
			nSum = max(nSum, vBuildingTimesSum[vvBuildTree[nStart][i]]);

		vIsBuilt[nStart] = true;
		vBuildingTimesSum[nStart] = nSum + vBuildingTimes[nStart];
		for (int i = 0; i < vvBuildTree[nStart].size(); i++)
			vBuildingTimesSum[nStart] = max(vBuildingTimesSum[nStart], vBuildingTimesSum[vvBuildTree[nStart][i]] + vBuildingTimes[nStart]);


	}

}