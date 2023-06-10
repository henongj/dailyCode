#include "20230607_studentManager.h"

void C20230607_STUDENT_MANAGER::init()
{
	m_mapStudent.insert({ 34, new C20230607_STUDENT{34, "김철수"} });
	m_mapStudent.insert({ 21453, new C20230607_STUDENT{ 21453, "김영희" } });
	m_mapStudent.insert({ 191243, new C20230607_STUDENT{ 191243, "김민수" } });
	
}

void C20230607_STUDENT_MANAGER::release()
{
	for (auto iter = m_mapStudent.begin(); iter != m_mapStudent.end(); ++iter)
	{
		delete iter->second;
		iter->second = nullptr;
	}
	m_mapStudent.clear();
}

bool C20230607_STUDENT_MANAGER::addStudent(int nID, const char* pName)
{
	std::map<int, C20230607_STUDENT*>::iterator iter = m_mapStudent.find(nID);

	if (iter != m_mapStudent.end())
	{
		printf("이미 존재하는 학생입니다.\n");
		return false;
	}

	m_mapStudent.insert({ nID, new C20230607_STUDENT{ nID, pName } });

	return true;
}

bool C20230607_STUDENT_MANAGER::eraseStudent(int nID, const char* pName)
{
	std::map<int, C20230607_STUDENT*>::iterator iter = m_mapStudent.find(nID);

	if (iter == m_mapStudent.end())
	{
		printf("존재하지 않는 학생입니다.\n");
		return false;
	}

	delete iter->second;
	m_mapStudent.erase(iter);
	
	return true;
}

C20230607_STUDENT* C20230607_STUDENT_MANAGER::findStudent(int nID)
{
	std::map<int, C20230607_STUDENT*>::iterator iterFind{};

	iterFind = m_mapStudent.find(nID);

	if(iterFind == m_mapStudent.end())
		return nullptr;

	return iterFind->second;
}
