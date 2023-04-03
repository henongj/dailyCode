#include "20230403_moveManager.h"

C20230403_MOVE* C20230403_MOVE_MANAGER::createMove(E_MOVE_TYPE eMoveType)
{
    C20230403_MOVE* pMove{};
    
    if(eMoveType == E_MOVE_TYPE::E_FLY)
		pMove = new C20230403_FLY{};
	else if (eMoveType == E_MOVE_TYPE::E_WALK)
		pMove = new C20230403_WALK();
	else if (eMoveType == E_MOVE_TYPE::E_SWIM)
		pMove = new C20230403_SWIM();

	return pMove;
}

void C20230403_MOVE_MANAGER::realseMove(C20230403_MOVE*& pMove)
{
	if (pMove)
	{
		delete pMove;
		pMove = nullptr;
	}
}
