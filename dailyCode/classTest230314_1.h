#pragma once

#include"classTest230314_0.h"

class classTest230314_1
{
private:
	classTest230314_0 m_cClassTest230314_0;

public:
	classTest230314_1() = default;
	explicit classTest230314_1(int nTestData);
	classTest230314_0* getTestData(void);
	void setTestData(int nTestData);

};