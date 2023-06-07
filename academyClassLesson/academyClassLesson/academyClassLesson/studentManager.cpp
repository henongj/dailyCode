#include "20230607_studentManager.h"

void C20230607_STUDENT_MANAGER::init()
{
	m_mapStudent.insert({ 34, new C20230607_STUDENT{34, "��ö��"} });
	m_mapStudent.insert({ 21453, new C20230607_STUDENT{ 21453, "�迵��" } });
	m_mapStudent.insert({ 191243, new C20230607_STUDENT{ 191243, "��μ�" } });
	
}

C20230607_STUDENT* C20230607_STUDENT_MANAGER::findStudent(int nID)
{
	std::map<int, C20230607_STUDENT*>::iterator iterFind{};

	iterFind = m_mapStudent.find(nID);

	if(iterFind == m_mapStudent.end())
		return nullptr;

	return iterFind->second;
}
