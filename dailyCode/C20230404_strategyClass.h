#pragma once
#include <iostream>

#include"C20230404_move.h"

__interface I20230404_Strategy
{
	//set move, get move
	void setMove(C20230404_MOVE* move);
	C20230404_MOVE* getMove();
	//init release
	void init();
	void release();
};

class C20230404_STRATEGY_CLASS abstract : public I20230404_Strategy
{
protected:
	C20230404_MOVE* m_pMove;
public:
	C20230404_STRATEGY_CLASS() = default;
	virtual ~C20230404_STRATEGY_CLASS() = default;
};

class C20230404_UNIT : public C20230404_STRATEGY_CLASS
{
public:
	C20230404_UNIT() = default;
	virtual ~C20230404_UNIT() = default;

	void init() override;
	void release() override;

	void setMove(C20230404_MOVE* move) override;
	C20230404_MOVE* getMove() override;
};