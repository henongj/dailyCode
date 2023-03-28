#pragma once

class C_20230322_class01
{
private:
	int* m_pData;

public:
	C_20230322_class01();
	C_20230322_class01(const C_20230322_class01& cInput);
	~C_20230322_class01();
	
	
	void setData(int nData);
	int getData();
};