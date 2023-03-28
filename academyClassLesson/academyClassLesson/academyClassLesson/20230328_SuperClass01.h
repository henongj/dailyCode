#pragma once

#include<iostream>

class C20230328_SUPERCLASS
{
public:
	C20230328_SUPERCLASS();
	// virtual이 있어야 자식클래스를 가리키는 포인터로 delete할 수 있다.
	virtual 
		~C20230328_SUPERCLASS();
};