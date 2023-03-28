#pragma once

#include"20230328_SuperClass02.h"


class C20230328_SUBCLASS_HUMAN : public C20230328_SUPERCLASS_ANIMAL
{
public:
	virtual void move(void);
	~C20230328_SUBCLASS_HUMAN() = default;
};