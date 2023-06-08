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

void C20230607_STUDENT::getId(int& nID)
{
	nID = m_nId;
}

std::string C20230607_STUDENT::getName(void)
{
	return m_strName;
}
