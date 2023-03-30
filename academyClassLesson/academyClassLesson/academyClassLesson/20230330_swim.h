#pragma once

#include"20230330_move.h"

class C_20230330_SWIM : public C20230330_MOVE
{
public:
	C_20230330_SWIM() = default;
	C_20230330_SWIM& operator=(const C_20230330_SWIM& other) = delete;
	C_20230330_SWIM(const C_20230330_SWIM& other) = delete;
	virtual ~C_20230330_SWIM() = default;
	void move() override;
};