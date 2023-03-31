#include "20230331_move_manager.h"
#include "20230331_move.h"

C20230331_MOVE_MANAGER::C20230331_MOVE_MANAGER()
{
}

void C20230331_MOVE_MANAGER::init()
{
	m_nMoveLength = 3;
	m_ppMove = new C20230331_MOVE * [m_nMoveLength] {};
	
	m_ppMove[0] = new C20230331_WALK();
	m_ppMove[1] = new C20230331_SWIM();
	m_ppMove[2] = new C20230331_FLY();
}

C20230331_MOVE* C20230331_MOVE_MANAGER::getMove(int nIndex)
{
	if (nIndex < 0 || nIndex >= m_nMoveLength)
		return nullptr;
	
    return nullptr;
}
