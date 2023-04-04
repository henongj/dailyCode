#include<iostream>
#include"20230403_moveManager.h"
#include"20230403_class.h"

void mainSpace04_20230403(void)
{
	C20230403_childClass cChild(3);
}

void mainSpace03_20230403(void)
{
	C20230403_MOVE_MANAGER cMoveManager{};

	C20230403_MOVE* pMove = cMoveManager.createMove(C20230403_MOVE_MANAGER::E_MOVE_TYPE::E_FLY);

	pMove->move();

	printf("삭제 전 : %p\n", pMove);
	cMoveManager.realseMove(pMove);
	printf("삭제 후 : %p\n", pMove);

	}


void mainSpace02_20230403(void)
{
	enum class E_STATE
	{
		E_NONE = 0,
		E_ROCK = 10,
		E_SISSOR = 11,
		E_PAPER = 12,
	};

	auto print = [](const E_STATE& eState)
	{
		printf("eState: %d\n", eState);
	};
	
	
	E_STATE eState1{};
	print(eState1);
	eState1 = E_STATE::E_ROCK;
	print(eState1);
	
}

void mainSpace01_20230403(void)
{
	enum E_STATE
	{
		E_ROCK = 0,
		E_SISSOR = 1,
		E_PAPER = 2,

	};

	void print(const E_STATE& eState);

	E_STATE eState1{};

	// 안 됨
	// eState1 = 10;
	eState1 = E_ROCK;

}

