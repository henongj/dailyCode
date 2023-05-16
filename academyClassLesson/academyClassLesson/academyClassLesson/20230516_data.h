#pragma once

#include<stdio.h>

class C20230516_DATA
{
private:
	int m_nData{};

public:
	C20230516_DATA() = default;
	
	void setData(int nData);
	int getData();
	void printData();
	void testFunc();
};