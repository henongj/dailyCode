#pragma once
#include<stdio.h>

class C20230529_BEVERAGE
{
public:
	virtual ~C20230529_BEVERAGE() = default;
	virtual void printName() abstract;
	
};

class C20230529_COFFEE : public C20230529_BEVERAGE
{
public:
	virtual void printName() override;
};

class C20230529_TEA : public C20230529_BEVERAGE
{
public:
	virtual void printName() override;
};

class C20230529_JUICE : public C20230529_BEVERAGE
{
public:
	virtual void printName() override;
};
