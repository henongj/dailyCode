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
	printf("\nprintArrSize ȣ��\n");
	printf("Size of arr: %d\n�迭�� ���̸� �Ҿ���.\n�׷��Ƿ� �迭�� �ѱ� �� ���̸� �ݵ�� �־���Ѵ�\n", nSizeOfArr);
}


void forcedDefineArrSize(int(*parr)[17]) {
	printf("\nforcedDefineArrSize ȣ��\n");
	printf("Size of arr: %zu\n���̰� �����Ǹ� ������ Ÿ�ӿ� �迭�� ���̸� ��Ȯ�� �Է��ؾ��Ѵ� \n ", sizeof(*parr) / sizeof(int));
}

void canGivePointerInsteadOfArr(int* nArr, int nArrSize)
{
	printf("\ncanGivePointerInsteadOfArr ȣ��\n");
	printf("Size of arr: %d\n������ �����Ϸ��� ���� �迭, ���Ƕ� �����ͷ� ����ϰ� �ڵ带 ¥�� �� �˾ƺ���\n ", nArrSize);
}