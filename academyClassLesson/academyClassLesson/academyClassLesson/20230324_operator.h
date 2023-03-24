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
	// �������� ���� �����ڸ� ���Ƴ����� �۵����� �ʴ´�
	//C20230324_C_DATA_02(const C20230324_C_DATA_02& _rCopy) = delete;

	void setData(int nData);
	int getData();
	// �̰� ��������. 
	C20230324_C_DATA_02& operator++();
	// �̰� ��������.
	const C20230324_C_DATA_02& operator++(int);
};