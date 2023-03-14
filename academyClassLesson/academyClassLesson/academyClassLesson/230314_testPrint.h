#pragma once

#include"230314_test.h"

class C_PRINT_230314
{
private:
	C_TEST_230314 m_cTest;
	
public:
	C_PRINT_230314() = default;
	C_TEST_230314* getData(void);
	
	void init(int nData);
	void printData(void);
};
