#pragma once

#include"20230601_base.h"

class C20230601_DECORATOR : public C20230601_BASE
{
protected:
	C20230601_BASE* m_pBase;
public:
	C20230601_DECORATOR(C20230601_BASE* pBase);
};
	
