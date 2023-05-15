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
/*

테스트

입력:

1000000
50 50 50 50 50 50
출력 : 250000000000000 (250조)

주의
'자료형' : long long

결과 시간 초과 
*/
void dataInput_acmicpc1041(int& nN, std::vector<long long int>& vDiceNumber)
{
	std::cin >> nN;
	vDiceNumber.resize(6);

	for (int i = 0; i < 6; i++)
		std::cin >> vDiceNumber[i];
}
int nCountOfOutside(int nPositionX, int nPositionY, int nPositionZ, int nN)
{
	int nCount{};

	nCount = 6;

	if (nPositionX + 1 < nN)
		nCount--;
	if (nPositionX - 1 >= 0)
		nCount--;
	if (nPositionY + 1 < nN)
		nCount--;
	if (nPositionY - 1 >= 0)
		nCount--;

	if (nPositionZ == 0)
		nCount -= 1;
	else
		nCount -= 2;

	return nCount;
}
void solution_acmicpc1041(void)
{
	int nN{};
	std::vector<long long int> vDiceNumber;
	long long int nMin{};
	// A : vDiceNumber[0] , B : 1 , C : 2 , D : 3 , E : 4 , F : 5

	dataInput_acmicpc1041(nN, vDiceNumber);
	std::sort(vDiceNumber.begin(), vDiceNumber.end());

	long long int arrDiceValue[7]{};
	arrDiceValue[0] = 0;
	for (int i = 0; i < 6; i++)
		arrDiceValue[i + 1] = arrDiceValue[i] + vDiceNumber[i];


	int nPositionX{};
	int nPositionY{};
	int nPositionZ{};


	//print vDice
	for (int i = 0; i < 6; i++)
		std::cout << vDiceNumber[i] << " ";
	std::cout << std::endl;

	//print
	for (int i = 0; i < 7; i++)
		std::cout << arrDiceValue[i] << " ";
	printf("\n");

	nMin = 0;
	for (nPositionZ = 0; nPositionZ < nN; nPositionZ++)
	{
		for (nPositionY = 0; nPositionY < nN; nPositionY++)
		{
			for (nPositionX = 0; nPositionX < nN; nPositionX++)
			{
				int nCount = nCountOfOutside(nPositionX, nPositionY, nPositionZ, nN);
				//print x y z count

				nMin += arrDiceValue[nCount];
			}
		}
	}

	std::cout << nMin;
}

int mainSpace01_acmicpc1041(void)
{
	solution_acmicpc1041();

	return 0;
}
