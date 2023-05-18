#include "20230517_baseBall.h"
#include<Windows.h>
#include<stdio.h>
#include<list>

void C20230517_baseBall::init(int nTableSize)
{
	srand(timeGetTime());

	m_nTableSize = nTableSize;
	m_pAnswer = nullptr;
	m_pTable = nullptr;

	C20230517_baseBall::makeAnswer();
	C20230517_baseBall::makeTable();

	m_pUserInput = new int[m_nTableSize] {};

}

void C20230517_baseBall::play(void)
{
	userInput();

	// 판정
	int m_arResult[(int)C20230517_table::e_result::E_MAX]{};
	
	for (int i = 0; i < m_nTableSize; i++)
	{
		m_arResult[ (int)m_pTable[i].getResult(m_pUserInput[i])] ++;
	}

	printf("strike : %d  ", m_arResult[(int)C20230517_table::e_result::E_STRIKE]);
	printf("ball : %d  ", m_arResult[(int)C20230517_table::e_result::E_BALL]);
	printf("out : %d  ", m_arResult[(int)C20230517_table::e_result::E_OUT]);
}
void C20230517_baseBall::userInput(void)
{
	bool arInputCheck[10]{};

	for (int i = 0; i < m_nTableSize; i++)
	{
		scanf_s("%d", &m_pUserInput[i]);
		while (arInputCheck[m_pUserInput[i]])
		{
			printf("중복입니다 다시 입력하세요\n");
			scanf_s("%d", &m_pUserInput[i]);
		}
		arInputCheck[m_pUserInput[i]] = true;
	}
}
void C20230517_baseBall::release()
{
	delete[] m_pTable;
	m_pTable = nullptr;
}
void C20230517_baseBall::printTables(void)
{
	for (int i = 0; i < m_nTableSize; i++)
	{
		m_pTable[i].printTable();
	}
}

void C20230517_baseBall::swapData(int& nData1, int& nData2)
{
	int nTemp = nData1;
	nData1 = nData2;
	nData2 = nTemp;
}

int C20230517_baseBall::RangedRand(int range_min, int range_max)
{
	int r = (int)(((double)rand() / (double)(RAND_MAX + 1)) * (range_max - range_min) + range_min);
	return r;
}

void C20230517_baseBall::shuffleArray(int* pData, int nLength, int nCount)
{
	for (int i = 0; i < nCount; i++)
	{
		swapData(pData[RangedRand(0, nLength)], pData[RangedRand(0, nLength)]);
	}
}

void C20230517_baseBall::makeAnswer(void)
{
	m_pAnswer = new int[m_nTableSize]{};

	int arNumber[10]{ 0,1,2,3,4,5,6,7,8,9 };
	shuffleArray(arNumber, 10, 50);
	printf("m_pAnswer: ");
	for (int i = 0; i < m_nTableSize; i++)
	{
		m_pAnswer[i] = arNumber[i];
		printf("%d, ", m_pAnswer[i]);
	}
	printf("\n");
}
void C20230517_baseBall::makeTable(void)
{
	m_pTable = new C20230517_table[m_nTableSize]{};

	std::list<int> listData{};

	printf("m_pTable : ");
	for (int i = 0; i < m_nTableSize; i++)
	{
		listData.push_back(m_pAnswer[i]);
		printf("%d, ", m_pAnswer[i]);
	}
	printf("\n");
	
	
	for (int i = 0; i < m_nTableSize; i++)
	{
		m_pTable[i].init(listData.begin(), listData.end());
		listData.push_back(*listData.begin());
		listData.pop_front();
	}
}