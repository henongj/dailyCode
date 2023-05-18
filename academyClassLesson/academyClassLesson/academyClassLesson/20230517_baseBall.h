#pragma once

#include<stdio.h>
#include"20230517_table.h"

class C20230517_baseBall
{
private:
	C20230517_table* m_pTable;
	int m_nTableSize;
	int* m_pAnswer;
	int* m_pUserInput;
private:
	void swapData(int& nData1, int& nData2);
	int RangedRand(int range_min, int range_max);
	void shuffleArray(int* pData, int nLength, int nCount);
	void makeTable();
	void makeAnswer();

	void userInput(void);

public:
	C20230517_baseBall() = default;
	~C20230517_baseBall() = default;

	void init(int nTableSize);
	void release();
	void printTables(void);
	
	void play();
};