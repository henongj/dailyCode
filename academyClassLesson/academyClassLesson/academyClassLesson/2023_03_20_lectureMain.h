#pragma once
//debug
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
//
#include<iostream>

int mainSpace01(void)
{
	int* p{};

	p = new int[5] {};

	p[3] = 123;
	for (int i = 0; i < 5; i++)
		printf("%d ", p[i]);

	delete[] p;
}

int mainSpace02(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(75);

	int* p1{};

	p1 = new int{};
	*p1 = 100;

	int* p2{};
	p2 = new int[5] {};

	int* p3{};
	p3 = new int[5] { 1, 2, 3, 4, 5 };

	int* p4{};
	p4 = new int[5] { 1, 2, 3, 4, 5 };

	delete p1;
	delete[] p3;
}