#include "20230607_bookManager.h"


void C20230607_bookManager::init()
{
	m_mapBook.clear();

	m_mapBook.insert({ 1, new C20230607_Book(1, "å�̸�1") });
	m_mapBook.insert({ 2, new C20230607_Book(2, "å�̸�1") });
	m_mapBook.insert({ 3, new C20230607_Book(3, "å�̸�1") });
	m_mapBook.insert({ 4, new C20230607_Book(3, "å�̸�2") });
	m_mapBook.insert({ 5, new C20230607_Book(3, "å�̸�3") });
	m_mapBook.insert({ 6, new C20230607_Book(3, "å�̸�4") });
	m_mapBook.insert({ 7, new C20230607_Book(3, "å�̸�5") });
}

void C20230607_bookManager::release()
{
	std::map<int, C20230607_Book*>::iterator iter = m_mapBook.begin();
	
	while (iter != m_mapBook.end())
	{
		delete iter->second;
		iter->second = nullptr;
		iter++;
	}
	
	m_mapBook.clear();
}

bool C20230607_bookManager::addBook(int nID, const char* pBookName)
{
	std::map<int, C20230607_Book*>::iterator iter = m_mapBook.find(nID);

	if (iter != m_mapBook.end())
	{
		printf("���̵� �ߺ��Ǿ����ϴ�.\n");
		return false;
	}
	
	m_mapBook.insert({ nID, new C20230607_Book(nID, pBookName) });
	return true;
}

bool C20230607_bookManager::eraseBook(int nID, const char* pBookName)
{
	std::map<int, C20230607_Book*>::iterator iter = m_mapBook.find(nID);
	
	if (iter == m_mapBook.end())
	{
		printf("���̵� �ش��ϴ� å�� �����ϴ�.\n");
		return false;
	}

	C20230607_Book* pBook = iter->second;

	delete pBook;
	pBook = nullptr;

	m_mapBook.erase(iter);
}

C20230607_Book* C20230607_bookManager::findBook(int nID)
{
	std::map<int, C20230607_Book*>::iterator iter = m_mapBook.find(nID);
	
	if (iter == m_mapBook.end())
	{
		printf("���̵� �ش��ϴ� å�� �����ϴ�.\n");
		return nullptr;
	}
	
	return iter->second;
}

void C20230607_bookManager::printAllBook(void)
{
	std::map<int, C20230607_Book*>::iterator iter = m_mapBook.begin();

	while (iter != m_mapBook.end())
	{
		printf("å ���̵� : %d, å �̸� : %s\n", iter->second->getID(), iter->second->getBookName().c_str());
		iter++;
	}
}
