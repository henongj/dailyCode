#include "20230530_character.h"

void C20230530_Character::init(void)
{
	m_pMove[(int)E20230530_MoveType::LAND] = new C20230530_factoryMove_Land();
	m_pMove[(int)E20230530_MoveType::WATER] = new C20230530_factoryMove_Water();
}

void C20230530_Character::release(void)
{
	for (int i = 0; i < (int)E20230530_MoveType::E_MAX; i++)
	{
		delete m_pMove[i];
		m_pMove[i] = nullptr;
	}
}

C20230530_Move* C20230530_Character::createMove(E20230530_MoveType eMoveType)
{
	return m_pMove[(int)eMoveType]->createMove();
}
