#pragma once

#include<iostream>
template<class T>
class C20230522_Array
{
private:
	T* m_pData;
	int m_nLength;

public:
	C20230522_Array() = default;
	~C20230522_Array() = default;

	C20230522_Array& operator=(const C20230522_Array&) = delete;
	C20230522_Array(const C20230522_Array&) = delete;

	void init(int nLength)
	{
		m_nLength = nLength;
		m_pData = new T[m_nLength]{};
	}

	void release()
	{
		delete[] m_pData;
		m_nLength = 0;
	}

	T operator[](int nIndex)
	{
		return m_pData[nIndex];
	}

	void setData(int nIndex, T& tData)
	{
		m_pData[nIndex] = tData;
	}
	T getData(int nIndex)
	{
		return m_pData[nIndex];
	}
	
};