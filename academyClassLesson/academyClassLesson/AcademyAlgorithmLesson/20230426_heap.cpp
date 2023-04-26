#include "20230426_heap.h"
#include<stdio.h>
void C20230426_HEAP::swapData(int& nDst, int& nSrc)
{
	int nData = nDst;
	nDst = nSrc;
	nSrc = nData;
}

void C20230426_HEAP::init(int nLength)
{
	m_nLength = nLength + 1;
	m_pBuffer = new int[m_nLength] {};

	m_nCount = 0;
}

void C20230426_HEAP::release(void)
{
	m_nCount = 0;
	m_nLength = 0;
	delete[] m_pBuffer;
	m_pBuffer = nullptr;
}

bool C20230426_HEAP::add(int nData)
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


bool C20230426_HEAP::add_recursion_logic(int nIndex, int nUp)
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

int C20230426_HEAP::getBig(int n1, int n2)
{
	int nBig{};
	nBig = n2;

	if (nBig < n1)
		nBig = n1;

	return nBig;
}


bool C20230426_HEAP::add_recursion(int nData)
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

void C20230426_HEAP::print(void)
{
	for (int i = 1; i <= m_nCount; i++)
		printf("%d ", m_pBuffer[i]);
	printf("\n");
}


int C20230426_HEAP::getLength(void)
{
	return m_nLength - 1;
}

bool C20230426_HEAP::pop(void)
{
	if (m_nCount - 1 <= 0)
		return false;

	erase();

	return true;
}

void C20230426_HEAP::erase()
{
	m_pBuffer[1] = m_pBuffer[m_nCount];
	m_nCount = m_nCount - 1;

	int nIndex{};
	int nLeft{};
	int nRight{};
	int nBig{};
	bool bLoop{};

	nIndex = 1;
	bLoop = true;
	nLeft = nIndex * 2;
	nRight = nIndex * 2 + 1;

	// 노드가 둘 다 있는 경우만 작업
	while (nLeft <= m_nCount && bLoop)
	{
		nBig = nLeft;
		if (nRight <= m_nCount && m_pBuffer[nLeft] < m_pBuffer[nRight])
			nBig = nRight;

		if (m_pBuffer[nIndex] < m_pBuffer[nBig])
			swapData(m_pBuffer[nIndex], m_pBuffer[nBig]);
		else
			bLoop = false;

		nIndex = nBig;
		nLeft = nIndex * 2;
		nRight = nIndex * 2 + 1;
	}

}
