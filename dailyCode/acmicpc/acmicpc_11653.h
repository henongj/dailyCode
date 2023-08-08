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

//https://www.acmicpc.net/problem/11653
//소인수분해
namespace acmicpc_11653
{
	void fDataInput(int& nData, int& nDivisor)
	{
		cin >> nData;
		nDivisor = 2;
	}

	void fGetAllDivisor(int nData, int nDivisor)
	{
		while (nData != 1)
		{
			if (nData % nDivisor == 0)
			{
				cout << nDivisor << endl;
				nData /= nDivisor;
			}
			else
				nDivisor++;
		}
	}

	void solution(void)
	{
		int nData{};
		int nDivisor{};
		fDataInput(nData, nDivisor);
		fGetAllDivisor(nData, nDivisor);
	}
}