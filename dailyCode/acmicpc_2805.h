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

//https://www.acmicpc.net/problem/2805
//나무 자르기
void acmicpc_2805(void)
{
	int nNumOfTree{};
	int nNeedLength{};
	std::vector<int> vTreeLength{};

	std::cin >> nNumOfTree;
	std::cin >> nNeedLength;

	vTreeLength.reserve(nNumOfTree);
	vTreeLength.resize(nNumOfTree);

	for (int i = 0; i < nNumOfTree; i++)
	{
		std::cin >> vTreeLength[i];
	}
	sort(vTreeLength.begin(), vTreeLength.end());

	int left = 0;
	int right = vTreeLength.back();
	int mid = 0;
	int result = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < nNumOfTree; i++)
		{
			if (vTreeLength[i] > mid)
			{
				sum += vTreeLength[i] - mid;
			}
		}
		if (sum >= nNeedLength)
		{
			result = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	std::cout << result << '\n';

}

