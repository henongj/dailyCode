#pragma once


void func(const int(&arData)[3])
{
	for (int i = 0; i < 3; i++)
	{
		printf("%d\b", arData[i]);
	}
}
