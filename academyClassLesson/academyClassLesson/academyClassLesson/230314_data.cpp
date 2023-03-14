#include "230314_data.h"
#include <stdio.h>

/* 
정상작동
C_TEST::C_TEST(int nData1) :
	m_nData1(nData1),
	m_nData2(m_nData1 * 2),
	m_nData3(m_nData2 * 2),
	m_nData4(m_nData3 * 2),
	m_nData5(m_nData4 * 2),
	m_nData6(m_nData5 * 2)
{
}
*/
// 오작동 이런 짓 안 한다
C_TEST::C_TEST(int nData1):
	m_nData3(nData1 * 2),
	m_nData6(m_nData1 * 2),
	m_nData4(m_nData3 * 2),
	m_nData5(m_nData4 * 2),
	m_nData1(m_nData2 * 8),
	m_nData2(m_nData1 * 2)
{

}

void C_TEST::print()
{
	printf("%d %d %d %d %d %d\n", m_nData1, m_nData2, m_nData3, m_nData4, m_nData5, m_nData6);
}
