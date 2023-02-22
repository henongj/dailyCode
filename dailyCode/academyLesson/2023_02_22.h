#pragma once
#include<iostream>

namespace academyLecture_2023_02_21
{
	using namespace std;

	int add(int nData1, int nData2);
	int add(const int* pData1, const int* pData2);
	void add(int nData1, int nData2, int* pResult);
	void add(const int* pData1, const int* pData2, int* pResult);

	bool getCircleRoundAndArea(float fRadius, float* pArea, float* pRound);

	bool getTriangleArea(float nLength1, float nLength2, float nLength3, float* fResult);
	float getTriangleArea(float nLength1, float nLength2, float nLength3);

	void getArraySum(int nArray[], int nSize, int* pSum);
	int getArraySum(int nArray[], int nSize);

	bool sortArray(const int* arrData, int* arrResult, int nSize);

	bool isPrimeNumber(int nNumber);

	int mainTest(void)
	{


	}


	int add(int nData1, int nData2)
	{
		int nResult{};
		nResult = nData1 + nData2;
		return nResult;
	}

	int add(const int* pData1, const int* pData2)
	{
		int nSum{};
		nSum = *pData1 + *pData2;
		return nSum;
	}

	void add(int nData1, int nData2, int* pResult)
	{
		*pResult = nData1 + nData2;
	}

	void add(const int* pData1, const int* pData2, int* pResult)
	{
		*pResult = *pData1 + *pData2;
	}

	bool getCircleRoundAndArea(float fRadius, float* pArea, float* pRound)
	{
		if (fRadius < 0)
			return false;

		float fResult{};
		fResult = fRadius * fRadius * (float)3.14;
		*pArea = fResult;
		fResult = fRadius * (float)2.0 * (float)3.14;
		*pRound = fResult;

		return true;
	}

	bool getTriangleArea(float fLength1, float fLength2, float fLength3, float* fResult)
	{
		if (fLength1 < (float)0 || fLength2 < (float)0 || fLength3 < (float)0)
			return false;

		float fResult{};
		float fHalfSum{};
		fHalfSum = (fLength1 + fLength2 + fLength3) / (float)2;

		*fResult = sqrt(fHalfSum * (fHalfSum - fLength1) * (fHalfSum - fLength2) * (fHalfSum - fLength3));

		return true;
	}

	float getTriangleArea(float fLength1, float fLength2, float fLength3)
	{

		float fResult{};
		float fHalfSum{};
		fHalfSum = (fLength1 + fLength2 + fLength3 / (float)2);

		fResult = sqrt(fHalfSum * (fHalfSum - fLength1) * (fHalfSum - fLength2) * (fHalfSum - fLength3));

		return fResult;

	}

	void getArraySum(int nArray[], int nSize, int* pSum)
	{
		int nResult = 0;
		for (int i = 0; i < nSize; i++)
			nResult += nArray[i];
		*pSum = nResult;

	}

	int getArraySum(int nArray[], int nSize)
	{
		int nResult = 0;
		for (int i = 0; i < nSize; i++)
			nResult += nArray[i];
		return nResult;
	}

	bool isPrimeNumber(int nNumber)
	{
		int nCount{};

		nCount = 0;

		for (int i = 1; i <= nNumber; i++)
		{
			if (nNumber % i == 0)
				nCount++;
		}

		if (nCount == 2)
			return true;
		else
			return false;
	}

}