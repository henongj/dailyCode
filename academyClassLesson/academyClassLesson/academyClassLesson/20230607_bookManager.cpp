#include "20230607_bookManager.h"

void C20230607_bookManager::registStudent(int nID, const char* pStudentName, std::set<S_INFO>::iterator iter)
{
	S_INFO* pInfo = new S_INFO{};

	pInfo->nID = nID;
	pInfo->pStudent = new C20230607_STUDENT(nID, pStudentName);
	pInfo->mapBookData.clear();
		
	m_setInfo.insert(iter, *pInfo);
}

void C20230607_bookManager::init()
{
	pInfoBuffer = new S_INFO{};
	pStudentBuffer = new C20230607_STUDENT(0, "");
	m_setInfo.clear();
}

void C20230607_bookManager::addBook(int nID, const char* pStudentName, const char* pBookName)
{
	pInfoBuffer->nID = nID;
	pInfoBuffer->pStudent = pStudentBuffer;
	pStudentBuffer->setId(nID);
	pStudentBuffer->setName(pStudentName);

	std::set<S_INFO>::iterator iter = m_setInfo.find(*pInfoBuffer);

	if (iter == m_setInfo.end())
		registStudent(nID, pStudentName, iter);
	
	
}
