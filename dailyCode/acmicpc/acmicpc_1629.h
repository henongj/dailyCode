
#ifndef ___acmicpc_1629_h___
#define ___acmicpc_1629_h___
//https://www.acmicpc.net/problem/1629
//°ö¼À
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

void inputData(long long& a, long long& b, long long& c)
{
	cin >> a >> b >> c;
}

void multiple(void)
{
	long long a{};
	long long b{};
	long long c{};
	long long result{};
	long long squareA{};
	long long halfB{};

	inputData(a, b, c);
	result = 1;
	squareA = a * a;
	halfB = b / 2;

	for (int i = 0; i < halfB; i++)
	{
		result = ((result % c) * (squareA % c)) % c;
	}
	if (b & 1)
		result = ((result % c) * (a % c)) % c;

	cout << result << endl;

}
/*

int main(void)
{
	multiple();
	return 0;

}
*/
#endif // !___acmicpc_1629_h___
