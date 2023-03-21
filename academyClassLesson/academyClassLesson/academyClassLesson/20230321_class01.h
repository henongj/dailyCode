#pragma once
#include<iostream>

class C20230321_01
{
private:
	int m_nData;
public:
	C20230321_01() = default;
	C20230321_01(const C20230321_01& c20230321_01) = delete;
	
	void setData(int nData);
	int getData(void);
	
};


void printC20230321_01(C20230321_01 c20230321_01);
