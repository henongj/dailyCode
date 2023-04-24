#include "20230424_heap.h"
#include<stdio.h>
void C20230424_HEAP::swapData(int& nDst, int& nSrc)
{
	int nData = nDst;
	nDst = nSrc;
	nSrc = nData;
}

void C20230424_HEAP::init(int nLength)
{
	m_nLength = nLength + 1;
	m_pBuffer = new int[m_nLength] {};
	
	m_nCount = 0;
}

void C20230424_HEAP::release(void)
{
	m_nCount = 0;
	m_nLength = 0;
	delete[] m_pBuffer;
	m_pBuffer = nullptr;
}

bool C20230424_HEAP::add(int nData)
{
	if (m_nCount >= m_nLength - 1)
		return false;

	int nIndex = m_nCount + 1;
	m_nCount = m_nCount + 1;
	
	m_pBuffer[nIndex] = nData;


	int nUp = nIndex / 2;
	while (nUp != E_NULL && m_pBuffer[nUp] < m_pBuffer[nIndex])
	{
		swapData(m_pBuffer[nUp], m_pBuffer[nIndex]);
		nIndex = nUp;
		nUp = nIndex / 2;
	}
	
    return true;
}


bool C20230424_HEAP::add_recursion_logic(int nIndex, int nUp)
{
	if (nUp == E_NULL)
		return false;

	if (m_pBuffer[nUp] < m_pBuffer[nIndex])
	{
		int nNextUp = nUp / 2;
		swapData(m_pBuffer[nUp], m_pBuffer[nIndex]);
		add_recursion_logic(nUp, nNextUp);
	}
	
	return true;
}

bool C20230424_HEAP::add_recursion(int nData)
{
	if (m_nCount >= m_nLength - 1)
		return false;

	int nIndex = m_nCount + 1;
	m_nCount = m_nCount + 1;
	
	m_pBuffer[nIndex] = nData;
	int nUp = nIndex / 2;

	bool bResult = add_recursion_logic(nIndex, nUp);
	
	return bResult;
}

void C20230424_HEAP::print(void)
{
	for (int i = 1; i <= m_nCount; i++)
		printf("%d ", m_pBuffer[i]);
	printf("\n");
}


int C20230424_HEAP::getLength(void)
{
	return m_nLength - 1;
}
