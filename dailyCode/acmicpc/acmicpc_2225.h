
//https://www.acmicpc.net/problem/2225
//ÇÕºÐÇØ
#ifndef ___acmicpc_2225_h___
#define ___acmicpc_2225_h___
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
#include<unordered_set>
using namespace std;

int decompositeSum(void)
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> vMemoiazation(k + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= n; ++i)
		vMemoiazation[1][i] = 1;
	for (int i = 2; i <= k; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			for (int l = 0; l <= j; ++l)
			{
				vMemoiazation[i][j] += vMemoiazation[i - 1][j - l];
				vMemoiazation[i][j] %= 1000000000;
			}
		}
	}
	cout << vMemoiazation[k][n] << endl;
	return 0;
}

/*
int main(void)
{
	decompositeSum();
	return 0;
}
*/
#endif // !___acmicpc_2225_h___