#pragma once

#include"20230529_Beverage.h"

class C20230529_FACTORY
{
public:
	virtual ~C20230529_FACTORY() = default;
	virtual C20230529_BEVERAGE* createBeverage() abstract;
	
};

class C20230529_COFFE_FACTORY : public C20230529_FACTORY
{
public:
	virtual C20230529_BEVERAGE* createBeverage() override;
};

class C20230529_TEE_FACTORY : public C20230529_FACTORY
{
public:
	virtual C20230529_BEVERAGE* createBeverage() override;
};
