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

//https://www.acmicpc.net/problem/11382
int solution(void)
{
	long long A{};
	long long B{};
	long long C{};
	long long nSum{};
	cin >> A >> B >> C;
	
	nSum = A + B + C;
	cout << nSum << endl;
	return 0;
}
