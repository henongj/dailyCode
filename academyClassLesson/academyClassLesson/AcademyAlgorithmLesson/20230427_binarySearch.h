#pragma once

const int* binarySearch(const int* pData, int nLength, int nFind)
{
	if (nLength <= 0)
		return nullptr;

	int nFindIndex = nLength / 2;

	if (pData[nFindIndex] > nFind)
		return binarySearch(pData, nFindIndex, nFind);
	
	if (pData[nFindIndex] < nFind)
		return binarySearch(pData + nFindIndex + 1, nLength - (nFindIndex + 1), nFind);

	return pData + nFindIndex;
}