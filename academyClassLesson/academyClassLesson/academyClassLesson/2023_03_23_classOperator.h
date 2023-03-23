#pragma once

class C20230323ClassOperator
{
private:
	int m_nData;

public:
	C20230323ClassOperator() = default;
	
	void setData(int nData);
	void printData(void);
	
	C20230323ClassOperator& operator+(int nData);
	C20230323ClassOperator& operator = (int nData);
	C20230323ClassOperator& operator = (C20230323ClassOperator& cData);
};


// 이게 빈 생성자를 만드는 법이다.
class C20230323EmptyClass
{
private:
public:
	C20230323EmptyClass() = default;
	C20230323EmptyClass(const C20230323EmptyClass&) = delete;
	C20230323EmptyClass& operator=(const C20230323EmptyClass&) = delete;
	
};