#pragma once

namespace n20230406_bubbleSort_01
{
	void swapInt(int& nData1, int& nData2);
	void bubbleSort(int* pArrayList, int nArrayLength);
	void bubbleSortLogic(int* pArrayList, int nArrayLength);
	void printArray(int* pArrayList, int nArrayLength);
	void runSpace(void);
}
namespace n20230406_bubbleSort_02
{
	void swapInt(int& nData1, int& nData2);
	void bubbleSort(int* pArrayList, int nArrayLength, bool isAscending);
	void bubbleSortLogic(int* pArrayList, int nArrayLength, bool isAscending);
	void printArray(const int* pArrayList, int nArrayLength);
	void runSpace(void);
}