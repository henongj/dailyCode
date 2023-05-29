#pragma once
#include"20230530_move.h"

class C20230530_factoryMove abstract
{
private:

public:
	virtual ~C20230530_factoryMove() = default;
	virtual C20230530_Move* createMove() abstract;
};

class C20230530_factoryMove_Land : public C20230530_factoryMove
{
private:

public:
	C20230530_factoryMove_Land() = default;
	~C20230530_factoryMove_Land() = default;

	C20230530_Move* createMove() override;
};

class C20230530_factoryMove_Water : public C20230530_factoryMove
{
private:

public:
	C20230530_factoryMove_Water() = default;
	~C20230530_factoryMove_Water() = default;

	C20230530_Move* createMove() override;
};
