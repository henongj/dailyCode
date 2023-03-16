#pragma once
#include<iostream>

bool getSum1(int nArr[], int nArrLength, int& nSum);
bool getSum2(int nArr[], int nArrLength, int* nSum);
int getSum3(int nArr[], int nArrLength);
int getSum4(int nArr[], int nArrLength, int* nSum);
int getSum5(int nArr[], int nArrLength, int* nSum);

bool swapNumber(int& nNumber1, int& nNumber2);
bool swapNumber(int* nNumber1, int* nNumber2);

bool interpolate1(int nNumber1, int nNumber2, float fRatio, int& nResult);
bool interpolate2(int nNumber1, int nNumber2, float fRatio, int* nResult);
int interpolate3(int nNumber1, int nNumber2, float fRatio);
int interpolate4(int nNumber1, int nNumber2, float fRatio, int* nResult);
int interpolate5(int nNumber1, int nNumber2, float fRatio, int& nResult);

void stringUpper1(char* strData);
char* stringUppder3(char* strLower);

bool getRoot1(float fValue, float& fRoot);
bool getRoot2(const float* fValue, float& fRoot);
bool getRoot3(const float& fValue, float& fRoot);
bool getRoot4(float fValue, float* fRoot);
bool getRoot5(const float* fValue, float* fRoot);
bool getRoot6(const float& fValue, float* fRoot);
float getRoot7(float fValue);
float getRoot8(float* fValue);
float getRoot9(float& fValue);
float getRoot10(float fValue, float& fRoot);
float getRoot11(float fValue, float* fRoot);

//이런거 하지마라
template<int nLength>
void printData(int(&arData)[nLength])
{
	for (int i = 0; i < nLength; i++)
	{
		printf("%d ", arData[i]);
	}
	puts("");
}
void usePrintDataTemplate(void)
{
	int arr1[5]{ 1,2,3,4,5 };
	int arr2[6]{ 1,2,3,4,5,6 };
	int arr3[7]{ 1,2,3,4,5,6,7 };
	printData(arr1);
	printData(arr2);
	printData(arr3);

}