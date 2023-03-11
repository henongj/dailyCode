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

//https://www.acmicpc.net/problem/25314
void solution(void)
{
	size_t szBite{};
	int nNumOfLong{};
	string strLong = "long";

	cin >> szBite;
	nNumOfLong = szBite / 4;

	for (int i = 0; i < nNumOfLong; i++)
		cout << strLong << " ";
	cout << "int";
}