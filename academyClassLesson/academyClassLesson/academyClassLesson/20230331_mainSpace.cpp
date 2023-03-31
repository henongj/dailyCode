#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include<iostream>
#include"20230331_move_manager.h"
#include"20230331_move.h"
#include"20230331_unit.h"
int mainSpace02_20230331(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	C20230331_MOVE_MANAGER* pMoveManager{};
	pMoveManager = new C20230331_MOVE_MANAGER();
	pMoveManager->init();

	C20230331_UNIT* pUnit = new C20230331_UNIT();
	pUnit->setMove(pMoveManager->getMove(0));
	pUnit->getMove()->Move();

	C20230331_UNIT* arUnit{};
	int nLength{};
	nLength = 5;
	arUnit = new C20230331_UNIT[nLength];

	arUnit[0].setMove(pMoveManager->getMove(0));
	arUnit[1].setMove(pMoveManager->getMove(1));
	arUnit[2].setMove(pMoveManager->getMove(2));
	arUnit[3].setMove(pMoveManager->getMove(2));
	arUnit[4].setMove(pMoveManager->getMove(1));

	for (int i = 0; i < nLength; i++)
		arUnit[i].getMove()->Move();


	pMoveManager->release();

	return 0;
}
int mainSpace01_20230331(void)
{
	C20230331_MOVE_MANAGER cMoveManager{};

	C20230331_UNIT arUnit[5]{};

	cMoveManager.init();

	C20230331_MOVE* pMove = cMoveManager.getMove(0);
	C20230331_UNIT cUnit{};
	cUnit.setMove(pMove);
	cUnit.getMove()->Move();

	arUnit[0].setMove(cMoveManager.getMove(0));
	arUnit[1].setMove(cMoveManager.getMove(1));
	arUnit[2].setMove(cMoveManager.getMove(2));
	arUnit[3].setMove(cMoveManager.getMove(0));
	arUnit[4].setMove(cMoveManager.getMove(2));

	return 0;
}