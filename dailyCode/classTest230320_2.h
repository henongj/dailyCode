#pragma once

#include"classTest230320.h"

class classTest230320_2
{
private:
	classTest230320_1 m_classTest230320_1;
public:
	classTest230320_2() = default;
	classTest230320_2(int nData1, int nData2);
	
	classTest230320_1* getTestClass230320_1(void);
	void setData(int nData1, int nData2);
	void printData(void);
};
