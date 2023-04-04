#pragma once

#include"20230403_factoryClass.h"

class C20230403_MOVE_MANAGER
{
public:
	enum class E_MOVE_TYPE
	{
		E_NONE = 0,
		E_FLY,
		E_WALK,
		E_SWIM,
	};

public:
	C20230403_MOVE* createMove(E_MOVE_TYPE eMoveType);
	void realseMove(C20230403_MOVE*& pMove);
};