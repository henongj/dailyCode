#include "20230526_studentManager.h"
#include<stdio.h>
bool C20230526_studentManager::addStudent(const char* pName, const char* pClass, int nGrade)
{
	iter = m_mapStudent.find(pName);
	if (iter != m_mapStudent.end())
		return false;

	C20230526_Student* pStudent{};

    pStudent = new C20230526_Student{};
	pStudent->init(pName, pClass, nGrade);

	m_mapStudent.insert(iter,{pName, pStudent});
	
	return true;
}

C20230526_Student* C20230526_studentManager::findStudent(const char* pName)
{
	iter = m_mapStudent.find(pName);

	if (iter == m_mapStudent.end())
		return nullptr;

	return iter->second;
}

void C20230526_studentManager::clear(void)
{
	iter = m_mapStudent.begin();
	while (iter != m_mapStudent.end())
	{
		delete(iter->second);
		iter++;
	}
	m_mapStudent.clear();
}

bool C20230526_studentManager::eraseStudent(const char* pName)
{
	iter = m_mapStudent.find(pName);
	if (iter->second == nullptr)
		return false;
	
	delete(iter->second);
	m_mapStudent.erase(iter);
	
	return true;
}


void C20230526_studentManager::printAllStudentInfo(void)
{
	iter = m_mapStudent.begin();
	while (iter != m_mapStudent.end())
	{
		iter->second->printStudentInfo();
		iter++;
	}
}
