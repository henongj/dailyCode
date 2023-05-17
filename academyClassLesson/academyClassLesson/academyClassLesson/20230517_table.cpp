#include "20230517_table.h"

void C20230517_table::init(int nStrike, int nBall1, int nBall2, int nBall4)
{
	m_arTable[nStrike] = e_result::E_STRIKE;
	m_arTable[nBall1] = e_result::E_BALL;
	m_arTable[nBall2] = e_result::E_BALL;
	m_arTable[nBall4] = e_result::E_BALL;
}


C20230517_table::e_result C20230517_table::getResult(int nStrike, int nBall, int nBall2, int nBall3)
{
    return e_result();
}
