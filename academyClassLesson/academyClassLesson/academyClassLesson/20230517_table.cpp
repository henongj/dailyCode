#include "20230517_table.h"

void C20230517_table::init(std::list<int>::iterator iterBegin, std::list<int>::iterator iterEnd)
{
	std::list<int>::iterator iter = iterBegin;

	m_arTable[*iter] = e_result::E_STRIKE;
	iter++;
	while(iter != iterEnd)
	{
		m_arTable[*iter] = e_result::E_BALL;
		iter++;
	}
}

C20230517_table::e_result C20230517_table::getResult(int nNumber)
{
	return m_arTable[nNumber];
}

void C20230517_table::printTable(void)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", m_arTable[i]);
	}
	printf("\n");
}