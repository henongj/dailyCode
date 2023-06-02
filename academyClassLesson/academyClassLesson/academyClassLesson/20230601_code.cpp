#include<iostream>
#include<set>

#include"20230601_pivoit.h"
#include"20230601_deco_A.h"


int mainSpace02_20230601(void)
{
	C20230601_BASE* pBase = new C20230601_PIVOT{};
	
	C20230601_DECORATOR* pDeco = new C20230601_DECO_A{ pBase };
	C20230601_DECORATOR* pDeco = new C20230601_DECO_A{ pBase };
	C20230601_DECORATOR* pDeco = new C20230601_DECO_A{ pBase };

	
	
	return 0;
}