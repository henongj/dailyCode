#pragma once
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
#include<stack>
#include<cmath>
#include<set>

#include "20230522_classTemplate.h"
#include "20230522_templateArray.h"
void mainSpace02_20230522(void);
void mainSpace02_20230522(void);


template<int nLength>
void printData_20230522(const int(&arrData)[nLength]);

template<class T>
T add(T t1, T t2);
template<>
char add(char t1, char t2);

template<typename T>
class C20230522_DATA
{
private:
	T m_tData;

public:
	C20230522_DATA() = default;
	~C20230522_DATA() = default;

	//delete copy and operator =
	C20230522_DATA(const C20230522_DATA&) = delete;
	C20230522_DATA& operator=(const C20230522_DATA&) = delete;

	void setData(T tData);
	T getData();
};

int mainSpace05_20230522(void)
{
	C20230522_Array<int> cArray{};

	cArray.init(10);
	for (int i = 0; i < 10; i++)
	{
		cArray.setData(i, i);
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << cArray[i] << ", " << cArray.getData(i) << "  ";
	}
	printf("\n");
	C20230522_Array<char> cArrayC{};

	cArrayC.init(10);
	char cData = 'A';
	for (int i = 0; i < 10; i++)
	{
		cArrayC.setData(i, cData);
		cData++;
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << cArrayC[i] << ", " << cArrayC.getData(i) << "  ";
	}


	return 0;
}


int mainSpace03_20230522(void)
{
	C20230522_DATA<int> cData1{};
	cData1.setData(101);

	printf("data : %d\n", cData1.getData());

	C20230522_DATA<float> cData2{};
	cData2.setData(110.5f);
	printf("data : %f\n", cData2.getData());

	return 0;
}


int mainSpace04_20230522(void)
{
	C20230522_Data<int> cDataP{};
	
	cDataP.setData(10);
	std::cout << cDataP.getData() << std::endl;

	C20230522_Data<char> cDataC{};
	cDataC.setData('a');
	std::cout << cDataC.getData() << std::endl;
	
	
	return 0;
}



void mainSpace02_20230522(void)
{
	add<int>(1, 2);
	add<float>(1.2f, 2.0f);
	add<char>('A', ' ');
}
int mainSpace01_20230522(void)
{
	int arData1[3]{ 3,2,1 };
	int arData2[4]{ 4,3,2,1 };
	int arData3[5]{ 5,4,3,2,1 };

	printData_20230522(arData1);
	printData_20230522(arData2);
	printData_20230522(arData3);


	return 0;
}


template<int nLength>
void printData_20230522(const int(&arrData)[nLength])
{
	for (int i = 0; i < nLength; i++)
	{
		printf("%d ", arrData[i]);
	}
	printf("\n");
}

template<class T>
T add(T t1, T t2)
{
	printf("template call\n");
	return t1 + t2;
}

template<>
char add(char t1, char t2)
{
	printf("template specilization call\n");
	return 0;
}

template<typename T>
void C20230522_DATA<T>::setData(T tData)
{
	m_tData = tData;
}

template<typename T>
T C20230522_DATA<T>::getData()
{
	return m_tData;
}
