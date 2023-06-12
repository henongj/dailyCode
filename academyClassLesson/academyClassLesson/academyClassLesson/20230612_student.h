#pragma once
#include<string>

class C202306121_STUDENT
{
private:
	std::string m_strName;
	int m_nID;
public:
	C202306121_STUDENT() = default;
	C202306121_STUDENT(const char* pName, int nID);
	~C202306121_STUDENT() = default;

	void setName(const char* pName);
	void setID(int nID);

	const char* getName(void);
	int getID(void);


};