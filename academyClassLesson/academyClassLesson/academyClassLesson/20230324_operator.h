#pragma once
#include<iostream>

class C20230324_C_DATA
{
private:
	int m_arData[5];
public:
	C20230324_C_DATA() = default;
	
	C20230324_C_DATA(const C20230324_C_DATA& _rCopy) = delete;
	C20230324_C_DATA& operator=(const C20230324_C_DATA& _rCopy) = delete;

	void setData(int nIndex, int nData);
	int& operator[](int nIndex);
};

class C20230324_C_DATA_02
{
private:
	int m_nData;
public:
	C20230324_C_DATA_02() = default;
	explicit C20230324_C_DATA_02(int nData);
	// 후증가는 복사 생성자를 막아놓으면 작동하지 않는다
	//C20230324_C_DATA_02(const C20230324_C_DATA_02& _rCopy) = delete;

	void setData(int nData);
	int getData();
	// 이건 전증가다. 
	C20230324_C_DATA_02& operator++();
	// 이건 후증가다.
	const C20230324_C_DATA_02& operator++(int);
};