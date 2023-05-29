#pragma once

#include"20230530_moveFactory.h"

class C20230530_Character 
{
public:
	enum class E20230530_MoveType
	{
		LAND,
		WATER,
		E_MAX
	};
private:
	C20230530_factoryMove* m_pMove[(int)E20230530_MoveType::E_MAX];

public:
	C20230530_Character() = default;
	~C20230530_Character() = default;

	void init(void);
	void release(void);

	C20230530_Move* createMove(E20230530_MoveType eMoveType);
};
