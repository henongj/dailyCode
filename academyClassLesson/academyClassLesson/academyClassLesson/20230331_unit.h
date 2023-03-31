#pragma once

#include"20230331_move.h"

class C20230331_UNIT
{
private:
	const C20230331_MOVE* m_pMove;
	
public:
	C20230331_UNIT() = default;
	~C20230331_UNIT() = default;

	void setMove(const C20230331_MOVE* pMove);
	const C20230331_MOVE* getMove();
};
