#pragma once
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


//https://www.acmicpc.net/problem/1041
//주사위


void dataInput_acmicpc1041(long long int& nN, std::vector<long long int>& vDiceNumber);
int nCountOfOutside(int nPositionX, int nPositionY, int nPositionZ, int nN);
void solution_acmicpc1041(void);
void getMinimumDiceValue(const std::vector<long long int>& vDiceNumber, std::vector<long long int>& vDiceValue);

int mainSpace02_acmicpc1041(void)
{
	solution_acmicpc1041();
	return 0;
}

void dataInput_acmicpc1041(long long int& nN, std::vector<long long int>& vDiceNumber)
{
	std::cin >> nN;
	vDiceNumber.resize(6);

	for (int i = 0; i < 6; i++)
		std::cin >> vDiceNumber[i];
}

void getMinimumDiceValue(const std::vector<long long int>& vDiceNumber, std::vector<long long int>& vDiceValue)
{
	vDiceValue.resize(4);
	vDiceValue[0] = 0;

	int nA = 0;	int nB = 1;	int nC = 2;	int nD = 3;	int nE = 4;	int nF = 5;

	//1개
	vDiceValue[1] = vDiceNumber[1];
	for (int i = 0; i < 6; i++)
		vDiceValue[1] = std::min(vDiceValue[1], vDiceNumber[i]);

	//2개 // A:B C D E , B: C D F , C : A B E F
	long long int nArr[10]{
		vDiceNumber[nA] + vDiceNumber[nB],
		vDiceNumber[nA] + vDiceNumber[nC],
		vDiceNumber[nA] + vDiceNumber[nD],
		vDiceNumber[nA] + vDiceNumber[nE],

		vDiceNumber[nB] + vDiceNumber[nC],
		vDiceNumber[nB] + vDiceNumber[nD],
		vDiceNumber[nB] + vDiceNumber[nF],

		vDiceNumber[nC] + vDiceNumber[nE],
		vDiceNumber[nC] + vDiceNumber[nF],

		vDiceNumber[nD] + vDiceNumber[nF]
	};

	vDiceValue[2] = nArr[0];
	for (int i = 0; i < 10; i++)
		vDiceValue[2] = std::min(vDiceValue[2], nArr[i]);

	//3개
	long long int nArr3[8]{
		vDiceNumber[nA] + vDiceNumber[nB] + vDiceNumber[nC],
		vDiceNumber[nA] + vDiceNumber[nB] + vDiceNumber[nD],
		vDiceNumber[nA] + vDiceNumber[nC] + vDiceNumber[nE],
		vDiceNumber[nA] + vDiceNumber[nD] + vDiceNumber[nE],

		vDiceNumber[nB] + vDiceNumber[nC] + vDiceNumber[nF],
		vDiceNumber[nB] + vDiceNumber[nD] + vDiceNumber[nF],

		vDiceNumber[nC] + vDiceNumber[nE] + vDiceNumber[nF],

		vDiceNumber[nD] + vDiceNumber[nE] + vDiceNumber[nF]
	};

	vDiceValue[3] = nArr3[0];
	for (int i = 0; i < 8; i++)
		vDiceValue[3] = std::min(vDiceValue[3], nArr3[i]);
}

void solution_acmicpc1041(void)
{
	long long int nN{};
	std::vector<long long int> vDiceNumber;
	std::vector<long long int> vDiceValue{};
	long long int nMin{};
	// A : vDiceNumber[0] , B : 1 , C : 2 , D : 3 , E : 4 , F : 5

	dataInput_acmicpc1041(nN, vDiceNumber);
	getMinimumDiceValue(vDiceNumber, vDiceValue);

	if (nN == 1)
	{
		long long int nSum{};
		long long int nMaxDiceValue{};
		nMaxDiceValue = vDiceNumber[0];
		for (int i = 0; i < vDiceNumber.size(); i++)
		{
			nSum += vDiceNumber[i];
			nMaxDiceValue = std::max(nMaxDiceValue, vDiceNumber[i]);
		}
		printf("%lld", nSum - nMaxDiceValue);
		return;
	}

	long long int nEntireSide = 5 * nN * nN - 8 * nN + 4;
	long long int nThreeSide = 4;
	long long int nTwoSide = 8 * nN - 12;
	long long int nOneSide = nEntireSide - nThreeSide - nTwoSide;

	//print nEntireSide, nThreeSide, nTwoSide, nOneSide
	//std::cout << nEntireSide << " " << nThreeSide << " " << nTwoSide << " " << nOneSide << std::endl;


	nMin = vDiceValue[1] * nOneSide +
		vDiceValue[2] * nTwoSide +
		vDiceValue[3] * nThreeSide;

	printf("%lld", nMin);
}


