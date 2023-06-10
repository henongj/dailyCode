#pragma once
#include<map>
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
class C20230607_STUDENT
{
private:
	int m_nId;
	std::string m_strName;

public:
	C20230607_STUDENT(int nID, const char* pName);
	~C20230607_STUDENT() = default;

	//delete copy , assgin operator
	C20230607_STUDENT(const C20230607_STUDENT&) = delete;
	C20230607_STUDENT& operator=(const C20230607_STUDENT&) = delete;

	void setId(int nID);
	void setName(const char* pName);

	void printInfo(void);

	
};