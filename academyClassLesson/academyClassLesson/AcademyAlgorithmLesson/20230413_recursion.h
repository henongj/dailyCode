#pragma once

#include<iostream>

void hanoi_20230413(int nNumber, char S, char T, char E);

int mainSpace01_20230413(void)
{
	int nNumber{};
	char cS{};
	char cT{};
	char cE{};

	nNumber = 4;
	cS = 'A';
	cT = 'B';
	cE = 'C';

	hanoi_20230413(nNumber, cS, cT, cE);

	return 0;
}

void hanoi_20230413(int nNumber, char S, char T, char E)
{
	if (nNumber <= 0)
		return;


	hanoi_20230413(nNumber - 1, S, E, T);
	printf("%c에서 %d번째 판을 %c 로 옮긴다 \n", S, nNumber, E);
	hanoi_20230413(nNumber - 1, T, S, E);
}

