#pragma once

#include<iostream>

template<typename T>
class C20230522_Data
{
private:
	T m_tData;

public:
	C20230522_Data() = default;
	~C20230522_Data() = default;

	//delete copy and operator =
	C20230522_Data(const C20230522_Data&) = delete;
	C20230522_Data& operator=(const C20230522_Data&) = delete;
	
	void setData(T tData)
	{
		m_tData = tData;
	}
	
	T getData(void)
	{
		return m_tData;
	}
};


template<>
class C20230522_Data<char>
{
private:
	char m_tData;

public:
	C20230522_Data() = default;
	~C20230522_Data() = default;

	//delete copy and operator =
	C20230522_Data(const C20230522_Data&) = delete;
	C20230522_Data& operator=(const C20230522_Data&) = delete;

	void setData(char cData)
	{
		printf("template specialization setData\n");
		m_tData = cData;
	}

	char getData(void)
	{
		printf("template specialization getData\n");
		return m_tData;
	}
};
