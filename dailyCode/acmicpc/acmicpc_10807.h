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

//https://www.acmicpc.net/problem/10807
//개수 세기

void fDataInput(int& nN, int& nInput1, int& nInput2, int& nTargetNumberCount, vector<int>& vNumberCount)
{
	cin >> nN;
	vNumberCount.resize(200);
	for (int i = 0; i < nN; i++)
	{
		cin >> nInput1;
		vNumberCount[nInput1 + 100] = vNumberCount[nInput1 + 100] + 1;
	}
	cin >> nInput2;
}
/*
int main(void)
{
	int nN{};
	int nInput1{};
	int nInput2{};
	int nTargetNumberCount{};
	vector<int> vNumberCount{};

	fDataInput(nN, nInput1, nInput2, nTargetNumberCount, vNumberCount);
	nTargetNumberCount = vNumberCount[nInput2 + 100];

	printf("%d", nTargetNumberCount);
}
*/