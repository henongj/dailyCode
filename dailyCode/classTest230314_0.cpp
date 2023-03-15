#include "classTest230314_0.h"
#include<stdio.h>
classTest230314_0::classTest230314_0(int nTestData)
{
	setTestData(nTestData);
}

int classTest230314_0::getTestData(void)
{
	return m_nTestData;
}

void classTest230314_0::setTestData(int nTestData)
{
	m_nTestData = nTestData;
}

