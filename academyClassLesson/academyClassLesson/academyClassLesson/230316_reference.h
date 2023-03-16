#pragma once
#include<iostream>

bool getSum1(const int nArr[], int nArrLength, int& nSum);
bool getSum2(const int nArr[], int nArrLength, int* pSum);
int getSum3(const int nArr[], int nArrLength);
int getSum4(const int nArr[], int nArrLength, int* pSum);
int getSum5(const int nArr[], int nArrLength, int* pSum);

bool swapNumber(int& nNumber1, int& nNumber2);
bool swapNumber(int* nNumber1, int* nNumber2);

bool interpolate1(int nNumber1, int nNumber2, float fRatio, int& nResult);
bool interpolate2(int nNumber1, int nNumber2, float fRatio, int* pResult);
int interpolate3(int nNumber1, int nNumber2, float fRatio);
int interpolate4(int nNumber1, int nNumber2, float fRatio, int* pResult);
int interpolate5(int nNumber1, int nNumber2, float fRatio, int& nResult);

void stringUpper1(char* strData);
bool stringUppder3(const char* strLower, char* strResult, int);

bool getRoot1(float fValue, float& fRoot);
bool getRoot2(const float* pValue, float& fRoot);
bool getRoot3(const float& fValue, float& fRoot);
bool getRoot4(float fValue, float* pRoot);
bool getRoot5(const float* pValue, float* pRoot);
bool getRoot6(const float& fValue, float* pRoot);
float getRoot7(float fValue);
float getRoot8(float* pValue);
float getRoot9(float& fValue);
void getRoot10(float fValue, float& fRoot);
void getRoot11(float fValue, float* pRoot);

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

void add(const int& n1, const int& n2, int& nResult);
void add(const int& n1, const int& n2, int* nResult);


void add(const int& n1, const int& n2, int& nResult)
{
	nResult = n1 + n2;
}

void add(const int& n1, const int& n2, int* nResult)
{
	*nResult = n1 + n2;
}
