#pragma once
#include<iostream>

class C_TEST_MALLOC
{
public:
	C_TEST_MALLOC();
};


C_TEST_MALLOC::C_TEST_MALLOC()
{
	// 이거 실행 안 돼
	printf("생성자\n");
}
