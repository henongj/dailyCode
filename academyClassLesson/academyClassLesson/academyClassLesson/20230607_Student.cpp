#include "20230607_Student.h"

C20230607_STUDENT::C20230607_STUDENT(int nID, const char* pName) :
	m_nId{}, m_strName{}
{
	m_nId = nID;
	m_strName = pName;
}

void C20230607_STUDENT::setId(int nID)
{
	m_nId = nID;
}

void C20230607_STUDENT::setName(const char* pName)
{
	m_strName = pName;
}

void C20230607_STUDENT::printInfo(void)
{
	printf("ID : %d, 학생 이름 : %s\n", m_nId, m_strName.c_str());
}


