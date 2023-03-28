#include "20230328_SubClass02.h"


C20230328_SUBCLASS_CAT::~C20230328_SUBCLASS_CAT()
{
	printf("C20230328_SUBCLASS_CAT 소멸자 호출\n");
}

void C20230328_SUBCLASS_CAT::move(void)
{
	printf("고양이 네발로 걷는다 호출\n");
}
