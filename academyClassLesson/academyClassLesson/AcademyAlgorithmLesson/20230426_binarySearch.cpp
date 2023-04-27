#include "20230426_binarySearch.h"
#include<stdio.h>

void C20230426_biniarySearch::init(int* pArray, int nLength)
{
	m_pArrayData = pArray;
	m_nLength = nLength;
}

void C20230426_biniarySearch::release()
{
	m_pArrayData = nullptr;
	m_nLength = 0;
}

void C20230426_biniarySearch::print()
{
	for (int i = 0; i < m_nLength; i++)
		printf("%d ", m_pArrayData[i]);
	printf("\n");
}

void C20230426_biniarySearch::search_loop(int nTarget, int*& pResult)
{
	int nFind = m_nLength / 2;
	int nLength = m_nLength;
	int* pData = m_pArrayData;

	while (nLength > 0 && !pResult)
	{
		if (pData[nFind] > nTarget)
			nLength = nFind;
		else if (pData[nFind] < nTarget)
		{
			pData = &pData[nFind + 1];
			nLength = nLength - (nFind + 1);
		}
		else
			pResult = &pData[nFind];

		nFind = nLength / 2;
	}	
}

void C20230426_biniarySearch::search_recursion_logic(const int* pArrayData, int nLength, int nTarget,const int*& pResult)
{
	if (nLength <= 0 || !(pResult == nullptr))
		return;

	int nFind = nLength / 2;
	const int* pData = pArrayData;

	if (pData[nFind] > nTarget)
	{
		nLength = nFind;
		search_recursion_logic(pData, nLength, nTarget, pResult);
	}
	else if (pData[nFind] < nTarget)
	{
		pData = &pData[nFind + 1];
		nLength = nLength - (nFind + 1);
		search_recursion_logic(pData, nLength, nTarget, pResult);
	}
	else
		pResult = &pData[nFind];
}


void binarySearch_20230426(int* arData, int nLength, int nTarget, int*& pResult)
{
	int nFind = nLength / 2;
	int* pData = arData;

	while (nLength > 0 && !pResult)
	{
		if (pData[nFind] > nTarget)
			nLength = nFind;
		else if (pData[nFind] < nTarget)
		{
			pData = &pData[nFind + 1];
			nLength = nLength - (nFind + 1);
		}
		else
			pResult = &pData[nFind];

		nFind = nLength / 2;
	}
}

/*
int arData[50]{};

	for (int i = 0; i < 50; i++)
	{
		arData[i] = i * 2;
	}

	int* pData = arData;
	int* pResult{};
	int nLength = 50;
	int nFind = nLength / 2;
	int nTarget = 38;

	while (nLength > 0 && !pResult)
	{
		if (pData[nFind] > nTarget)
			nLength = nFind;
		else if (pData[nFind] < nTarget)
		{
			pData = &pData[nFind + 1];
			nLength = nLength - (nFind + 1);
		}
		else
			pResult = &pData[nFind];

		nFind = nLength / 2;
	}

	if (pResult != nullptr)
		std::cout << "Found : " << *pResult << std::endl;
	else
		std::cout << "Not Found" << std::endl;

	pResult = nullptr;

	C20230426_biniarySearch cBinarySearch{};
	cBinarySearch.init(arData, 50);
	cBinarySearch.print();

	cBinarySearch.getDataAddress(38, pResult);

	if (pResult != nullptr)
		std::cout << "Found : " << *pResult << std::endl;
	else
		std::cout << "Not Found" << std::endl;


*/