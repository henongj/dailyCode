#include "20230517_baseBall.h"
#include<Windows.h>
#include<stdio.h>
#include<list>

void C20230517_baseBall::init(int nTableSize)
{
	srand(timeGetTime());

	m_nTableSize = nTableSize;

	m_pTable = new C20230517_table[m_nTableSize]{};

	int arData[10]{ 0, 1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < 50; i++)
	{
		swapData(arData[RangedRand(0, 10)], arData[RangedRand(0, 10)]);
	}
	
	std::list<int> listData{};
	for (int i = 0; i < m_nTableSize; i++)
	{
		listData.push_back(arData[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		std::list<int>::iterator iter = listData.begin();
		while (iter != listData.end())
		{
			printf("%d ", *iter);
			iter++;
		}
		printf("\n");

		listData.push_back(*(listData.begin()));
		listData.pop_front();
	}

}

void C20230517_baseBall::release()
{
	delete[] m_pTable;
	m_pTable = nullptr;
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
