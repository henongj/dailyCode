#include<iostream>
//https://www.acmicpc.net/problem/2480
//주사위 세개

void fCountIsSameNumber(const int& nA, const int& nB, bool& isSame, int& nCount)
{
	if (nA == nB)
	{
		isSame = true;
		nCount++;
	}
}

void fGivePriceToDiceGame(void)
{
	int aDice[3]{};
	int nHowManyDiceNumberIsSame{};
	bool isSame01{};
	bool isSame02{};
	bool isSame12{};

	nHowManyDiceNumberIsSame = 1;
	std::cin >> aDice[0] >> aDice[1] >> aDice[2];

	fCountIsSameNumber(aDice[0], aDice[1], isSame01, nHowManyDiceNumberIsSame);
	fCountIsSameNumber(aDice[0], aDice[2], isSame02, nHowManyDiceNumberIsSame);
	fCountIsSameNumber(aDice[1], aDice[2], isSame12, nHowManyDiceNumberIsSame);


	if (nHowManyDiceNumberIsSame == 2)
	{
		int nSameNumber{};
		if (isSame01)
			nSameNumber = aDice[0];
		if (isSame02)
			nSameNumber = aDice[0];
		if (isSame12)
			nSameNumber = aDice[1];
		std::cout << 1000 + (nSameNumber * 100);
	}
	else if (nHowManyDiceNumberIsSame == 1)
	{
		int nBiggestNumber{};
		nBiggestNumber = aDice[0];
		if (nBiggestNumber < aDice[1])
			nBiggestNumber = aDice[1];
		if (nBiggestNumber < aDice[2])
			nBiggestNumber = aDice[2];
		std::cout << nBiggestNumber * 100;
	}
	else
		std::cout << 10000 + (aDice[0] * 1000);

}