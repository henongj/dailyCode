#pragma once
#include <iostream>



class classTest230320_1
{
private:
	int m_nData;
	int m_nData2;
public:
	classTest230320_1() = default;
	classTest230320_1(int nData, int nData2);
	void setData(int nData, int nData2);
	void printData(void);
	
};
