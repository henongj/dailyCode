#pragma once

class C20230323ClassOperator
{
private:
	int m_nData;

public:
	C20230323ClassOperator() = default;
	
	void setData(int nData);
	void printData(void);
	
	C20230323ClassOperator& operator+(int nData);
	C20230323ClassOperator& operator = (int nData);
	C20230323ClassOperator& operator = (C20230323ClassOperator& cData);
};
