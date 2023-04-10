#pragma once
#include<iostream>

class C_20230410_01
{
private:
	int m_nData1{};
	int m_nData2{};
	int m_arData[5]{};
	float m_fData{};

public:
	C_20230410_01() = default;
	virtual void test();
};

class C_20230410_01_child : public C_20230410_01
{
private:
	int m_nChild;
public:
	virtual void test() override;
};

