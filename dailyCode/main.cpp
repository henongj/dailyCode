#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
#include<stack>
#include<cmath>
#include<set>

#include"20230530_character.h"

int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	C20230530_Character character{};
	character.init();

	C20230530_Move* pMove = character.createMove(C20230530_Character::E20230530_MoveType::LAND);

	pMove->printMoveSound();
	pMove->printMoveSpeed();

	delete pMove;
	
	character.release();
	
	return 0;
}
