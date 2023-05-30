#pragma once
#include<stdio.h>

__interface I20230530_OBSERVER
{
	void update(int nData);
	
};

class C20230530_OBSERVER abstract : public I20230530_OBSERVER
{
public:
	virtual ~C20230530_OBSERVER() = default;
};

class C20230530_GUI : public C20230530_OBSERVER
{
public:
	virtual void update(int nData) override;
};

class C20230530_TEXTUI : public C20230530_OBSERVER
{
public:
	virtual void update(int nData) override;
};
