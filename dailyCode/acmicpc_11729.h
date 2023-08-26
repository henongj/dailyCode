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

//https://www.acmicpc.net/problem/11729
namespace acmicpc_11729
{
	using namespace std;

	void solution(void);
	void hanoiRecursion(int nNumber, int nFrom, int nTo, int nBy);

	void solution(void)
	{
		std::ios_base::sync_with_stdio(false);
		std::cin.tie(NULL);
		std::cout.tie(NULL);
		int nNumber{};
		int nTimes{};

		cin >> nNumber;

		nTimes = pow(2, nNumber) - 1;

		cout << nTimes << endl;

		hanoiRecursion(nNumber, 1, 3, 2);
	}
	void hanoiRecursion(int nNumber, int nFrom, int nTo, int nBy)
	{
		std::ios_base::sync_with_stdio(false);
		std::cin.tie(NULL);
		std::cout.tie(NULL);
		// 출력 방식은 A 에서 B로 옮겼다는 뜻으로 A B 순서로 출력
		if (nNumber == 1)
		{
			cout << nFrom << " " << nTo << "\n";
			return;
		}

		hanoiRecursion(nNumber - 1, nFrom, nBy, nTo);
		cout << nFrom << " " << nTo << "\n";
		hanoiRecursion(nNumber - 1, nBy, nTo, nFrom);
	}
}