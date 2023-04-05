#pragma once

#include"C20230404_move.h"

class C20230404_FLY : public C20230404_MOVE
{
public:
	// C20230404_MOVE을(를) 통해 상속됨
	virtual void setMove(C20230404_MOVE* move) override;
	virtual C20230404_MOVE* getMove() override;
	virtual void init() override;
	virtual void release() override;

	//delete copy, assign operator
	C20230404_FLY(const C20230404_FLY&) = delete;
	C20230404_FLY& operator=(const C20230404_FLY&) = delete;
};