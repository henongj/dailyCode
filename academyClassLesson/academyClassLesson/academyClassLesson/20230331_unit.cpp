#include "20230331_unit.h"

void C20230331_UNIT::setMove(const C20230331_MOVE* pMove)
{
	m_pMove = pMove;
}

const C20230331_MOVE* C20230331_UNIT::getMove()
{
    return m_pMove;
}
