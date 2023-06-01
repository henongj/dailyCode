#pragma once


#include"20230601_deco.h"

class C20230601_DECO_A : public C20230601_DECORATOR
{
public:
	C20230601_DECO_A(C20230601_BASE* pBase);
	virtual void run() override;
};