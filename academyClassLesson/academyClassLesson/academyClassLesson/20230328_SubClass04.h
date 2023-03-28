#pragma once

#include"20230328_SuperClass02.h"

class C20230328_SUBCLASS_BIRD : public C20230328_SUPERCLASS_ANIMAL
{
public:
	~C20230328_SUBCLASS_BIRD() = default;
	virtual void move(void) override;
};