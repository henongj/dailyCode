#include<iostream>

#include"20230321_class01.h"


int mainSpace(void)
{
	C20230321_01 c20230321_01{};

	c20230321_01.setData(10);
	
	//복사생성자 형식으로 함수를 만들고 호출하려고 하면 에러가 뜬다 
	//printC20230321_01(c20230321_01);
	return 0;

}
