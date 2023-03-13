#pragma once

class C_ADD
{
private:
	int m_nData1;
	int m_nData2;
public:
	C_ADD() = default;
	void setData(int nData1, int nData2);
	int getSum();
};
