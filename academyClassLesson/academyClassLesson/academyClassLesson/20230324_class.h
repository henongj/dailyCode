#pragma once
#include<iostream>
class C20230324_DATA_01
{
public:
	C20230324_DATA_01() = default;
	C20230324_DATA_01(const C20230324_DATA_01& c)
	{
		printf("복사 생성자 \n");
	}
};

