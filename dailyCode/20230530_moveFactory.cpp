#include "20230530_moveFactory.h"

C20230530_Move* C20230530_factoryMove_Land::createMove()
{
	return new C20230530_Move_Land{};
}

C20230530_Move* C20230530_factoryMove_Water::createMove()
{
	return new C20230530_Move_Water{};
}
