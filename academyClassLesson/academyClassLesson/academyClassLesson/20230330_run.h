#pragma once


#include"20230330_move.h"

class C_20230330_RUN : public C20230330_MOVE
{
public:
	C_20230330_RUN() = default;
	C_20230330_RUN& operator=(const C_20230330_RUN& other) = delete;
	C_20230330_RUN(const C_20230330_RUN& other) = delete;
	virtual ~C_20230330_RUN() = default;
	void move() override;
};