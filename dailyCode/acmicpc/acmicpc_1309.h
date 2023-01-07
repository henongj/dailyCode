
//https://www.acmicpc.net/problem/1309
//1309. µ¿¹°¿ø
#ifndef ___acmicpc_1309_h___
#define ___acmicpc_1309_h___
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
using namespace std;

void get_all_case_live_in_lion(void)
{
	int N;
	cin >> N;

	int mod = 9901;
	vector<vector<int>> dp(N + 1, vector<int>(3, 0));
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
	}

	cout << (dp[N][0] + dp[N][1] + dp[N][2]) % mod << endl;
}
/*
N = 1 , 3
N = 2 , 7
N = 3 , 17
N = 4 , 41
N = 5 , 99
int main() {

	get_all_case_live_in_lion();
	return 0;
}
*/
#endif // ___acmicpc_1309_h___
