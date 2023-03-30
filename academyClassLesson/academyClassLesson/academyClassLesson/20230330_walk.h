#pragma once

#include"20230330_move.h"

class C_20230330_WALK : public C20230330_MOVE
{
public:
	C_20230330_WALK() = default;
	C_20230330_WALK& operator=(const C_20230330_WALK& other) = delete;
	C_20230330_WALK(const C_20230330_WALK& other) = delete;
	virtual ~C_20230330_WALK() = default;
	void move() override;
};