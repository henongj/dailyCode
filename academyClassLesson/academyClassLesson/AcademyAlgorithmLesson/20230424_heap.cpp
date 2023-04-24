#include "20230424_heap.h"
#include<stdio.h>
void C20230424_HEAP::init(int nLength)
{
	m_nLength = nLength;
	m_pBuffer = new int[nLength];
}

void C20230424_HEAP::release(void)
{
	m_nLength = 0;
	delete[] m_pBuffer;
	m_pBuffer = nullptr;
}

bool C20230424_HEAP::add(int nData)
{
    return false;
}

void C20230424_HEAP::print(void)
{
	for (int i = 1; i < m_nLength; i++)
	{
		printf("%d ", m_pBuffer[i]);
	}
	printf("\n");
}
