#include<iostream>
#include<Windows.h>
#include"20230517_baseBall.h"

int main(void)
{
	srand(timeGetTime());

	C20230517_baseBall cBaseBall;

	cBaseBall.init(4);
	
	return 0;
}

