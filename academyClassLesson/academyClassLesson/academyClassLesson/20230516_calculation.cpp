#include "20230516_calculation.h"

void C20230516_calculation::add()
{
	m_nResult = m_nData1 + m_nData2;
}

void C20230516_calculation::sub()
{
	m_nResult = m_nData1 - m_nData2;
}

void C20230516_calculation::mul()
{
	m_nResult = m_nData1 * m_nData2;
}

void C20230516_calculation::div()
{
	m_nResult = m_nData1 / m_nData2;
}

void C20230516_calculation::mod()
{
	m_nResult = m_nData1 % m_nData2;
}

void C20230516_calculation::init(void)
{
	m_arrFunc[(int)(E_OPERATOR::E_ADD)] = &C20230516_calculation::add;
	m_arrFunc[(int)(E_OPERATOR::E_SUB)] = &C20230516_calculation::sub;
	m_arrFunc[(int)(E_OPERATOR::E_MUL)] = &C20230516_calculation::mul;
	m_arrFunc[(int)(E_OPERATOR::E_DIV)] = &C20230516_calculation::div;
	m_arrFunc[(int)(E_OPERATOR::E_MOD)] = &C20230516_calculation::mod;
	
}

void C20230516_calculation::setData(int nData1, int nData2)
{
	m_nData1 = nData1;
	m_nData2 = nData2;
}

void C20230516_calculation::update(E_OPERATOR eOperator)
{
	(this->*m_arrFunc[(int)(eOperator)])();
}

int C20230516_calculation::getResult(void)
{
    return m_nResult;
}
