#pragma once

#include<iostream>

void printArrSize(int* nArr);
void forcedDefineArrSize(int(*pArr)[17]);
void canGivePointerInsteadOfArr(int* nArr, int nArrSize);
int mainSpace(void)
{
	int nArr[17] = { 0, };
	printArrSize(nArr);
	forcedDefineArrSize(&nArr);
	canGivePointerInsteadOfArr(nArr, 17);
	return 0;
}

void printArrSize(int* nArr)
{
	int nSizeOfArr{};

	nSizeOfArr = sizeof(*nArr);
	printf("\nprintArrSize 호출\n");
	printf("Size of arr: %d\n배열의 길이를 잃었다.\n그러므로 배열을 넘길 땐 길이를 반드시 주어야한다\n", nSizeOfArr);
}


void forcedDefineArrSize(int(*parr)[17]) {
	printf("\nforcedDefineArrSize 호출\n");
	printf("Size of arr: %zu\n길이가 강제되며 컴파일 타임에 배열의 길이를 정확히 입력해야한다 \n ", sizeof(*parr) / sizeof(int));
}

void canGivePointerInsteadOfArr(int* nArr, int nArrSize)
{
	printf("\ncanGivePointerInsteadOfArr 호출\n");
	printf("Size of arr: %d\n어차피 컴파일러는 선언때 배열, 정의때 포인터로 명시하고 코드를 짜도 못 알아본다\n ", nArrSize);
}