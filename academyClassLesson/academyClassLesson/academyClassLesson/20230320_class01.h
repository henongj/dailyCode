#pragma once

class class01_20230320_01
{
private:
	//선언에선 메모리가 안 잡혀있다 
	int* m_pData;
public:
	// 여기서 몇 개나 쓸지 잡혀. 그래서 로딩이 되는거야
	void init();
};

class class01_20230320_02
{
private:
	int m_arData[5];
public:
	void init();
};

