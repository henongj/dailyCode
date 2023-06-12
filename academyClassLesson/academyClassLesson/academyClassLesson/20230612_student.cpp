#include "20230612_student.h"

C202306121_STUDENT::C202306121_STUDENT(const char* pName, int nID) :
	m_nID{}, m_strName{}
{
	m_nID = nID;
	m_strName = pName;
}

void C202306121_STUDENT::setName(const char* pName)
{
	m_strName = pName;
}

void C202306121_STUDENT::setID(int nID)
{
	m_nID = nID;
}

const char* C202306121_STUDENT::getName(void)
{
	return m_strName.c_str();
}

int C202306121_STUDENT::getID(void)
{
	return m_nID;
}
